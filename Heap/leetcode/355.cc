#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

class comp {
    public:
        bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
            return a.first > b.first;
        }
};

class User {
    public:
        int id;
        unordered_set<int> followings;
        vector<pair<int, int>> posts;

        User(int uid = -1): id(uid) {}

        void tweet(int time, int tweetId) {
            posts.push_back({time, tweetId});
        }

        void follow(User &followee) {
            followings.insert(followee.id);
            return;
        }

        void unfollow(User &followee) {
            followings.erase(followee.id);
            return;
        }
};

class Twitter {
    private:
        map<int, User*> users;
        int count;

    public:
        Twitter() {
            count = 0;
        }

        ~Twitter() {
            for(auto pr : users) {
                delete pr.second;
            }
        }

        User* addUser(int userId) {
            User *user = new User(userId);
            users.insert({userId, user});
            return user;
        }

        void postTweet(int userId, int tweetId) {
            User *user;
            if(users.count(userId)) {
                user = users[userId];
            }
            else {
                user = addUser(userId);
            }
            user->tweet(count, tweetId);
            count ++;
            return;
        }

        vector<int> getNewsFeed(int id) {
            // get the user
            if(!users.count(id))
                return {};
            User *user = users[id];
            priority_queue<pair<int, int>, vector<pair<int, int>>, comp> top10;
            // search every followee and itself
            for(auto followeeId : user->followings) {
                User *followee = users[followeeId];
                int i = 0;
                for(auto tweetId = followee->posts.rbegin(); tweetId != followee->posts.rend(); tweetId++) {
                    i++;
                    if(i > 10) break;
                    if(top10.size() >= 10) {
                        if(top10.top().first > tweetId->first) {
                            break;
                        }
                        top10.pop();
                    }
                    top10.push(*tweetId);
                }
            }
            int i = 0;
            for(auto tweetId = user->posts.rbegin(); tweetId != user->posts.rend(); tweetId++) {
                i++;
                if(i > 10)
                    break;
                if(top10.size() >= 10) {
                    if(top10.top().first > tweetId->first) {
                        continue;
                    }
                    top10.pop();
                }
                top10.push(*tweetId);
            }
            vector<int> news;
            while(!top10.empty()) {
                news.push_back(top10.top().second);
                top10.pop();
            }
            reverse(news.begin(), news.end());
            return news;
        }

        void follow(int followerId, int followeeId) {
            if(!users.count(followerId)) {
                addUser(followerId);
            }
            if(!users.count(followeeId))
                addUser(followeeId);
            users[followerId]->follow(*users[followeeId]);
        }

        void unfollow(int followerId, int followeeId) {
            if(!users.count(followerId)) {
                cout << "user with id : " << followerId << " NOT FOUND";
                cout << " | CAN'T MAKE IT UNFOLLOW";
                cout << endl;
                return;
            }
            users[followerId]->unfollow(*users[followeeId]);
        }
};
