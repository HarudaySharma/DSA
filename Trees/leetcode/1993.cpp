#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class TreeNode {
    public:
        TreeNode *left;
        int val;
        TreeNode *right;
        TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

class LockingTree {
    private:
        TreeNode *root = nullptr;
        unordered_map<TreeNode*,int>hash;

    public:
        LockingTree(vector<int> &parent) {
            int n = parent.size();
            if(n == 0) 
                return;
            TreeNode* newNode = new TreeNode(0);
            unordered_map<int, TreeNode*>createdNodes;
            queue<TreeNode*>q;
            root = newNode;
            q.push(root);
            createdNodes.insert({0, newNode});
            int i = 1;
            for (int i = 1; i < n; ++i) {
                auto it = createdNodes.find(parent[i]);
                if (it == createdNodes.end()) {
                    // create the parent
                    TreeNode *newNode = new TreeNode(parent[i]);
                    createdNodes.insert({parent[i], newNode});
                    it = createdNodes.find(parent[i]);
                }

                TreeNode *child = new TreeNode(i);
                if (!it->second->left) {
                    it->second->left = child;
                } else {
                    it->second->right = child;
                }

                createdNodes.insert({i , child});
            }
            displayTree(root);
        }
        void displayTree(TreeNode* root) {
            if(!root) {
                return;
            }
            cout << "parent: " << root->val << "|";
            int left = root->left ? root->left->val: -1;
            cout << "left: " << left << " ";
            int right = root->right ? root->right->val: -1;
            cout << "right: " << right << " ";
            cout << endl;
            displayTree(root->left);
            displayTree(root->right);
        }

        bool lock(int num, int user) {
            TreeNode* node = findNode(root, num);
            auto it = hash.find(node);
            if(it != hash.end())
                return false;
            hash[node] = user;
            return true;
        }

        bool unlock(int num, int user) {
           TreeNode* node = findNode(root, num);
           auto it = hash.find(node);
           if(it != hash.end() && it->second == user) {
               hash.erase(it);
               return true;
           }
           return false;
       }

        /*
         * 1. ansector should be unlocked
         * 2. node should be unlocked
         * 3. at least one descendent should be locked
         */
        bool upgrade(int num, int user) {
            bool ansectorLocked = false;
            TreeNode* node = findNode(root, num, ansectorLocked);
            if (root->val != num && ansectorLocked) 
                return false;

            auto it = hash.find(node);
            if(root->val == num || it == hash.end() || (it != hash.end() && it->second == user)) {
                bool descendentLocked = false;
                unlockDescendents(node, descendentLocked);
                if(descendentLocked) {
                    hash[node] = user;
                    return true;
                }
            }
            return false;
        }

        void unlockDescendents(TreeNode* root, bool &descendentLocked) {
            if(!root) {
                return;
            }
            auto left = root->left ? hash.find(root->left) : hash.end();
            auto right = root->right ? hash.find(root->right) : hash.end();
            if(left != hash.end()) {
                descendentLocked = true;
                hash.erase(left);
            }
            if(right != hash.end()) {
                descendentLocked = true;
                hash.erase(right);
            }
            unlockDescendents(root->left, descendentLocked);
            unlockDescendents(root->right, descendentLocked);
        }

        TreeNode* findNode(TreeNode* root, int val, bool &ansectorLocked){
            if(!root) {
                return nullptr;
            }
            if(root->val == val) {
                return root;
            }

            TreeNode* nodeLeft = findNode(root->left, val, ansectorLocked);
            if(nodeLeft) {
                if(!ansectorLocked && hash.count(root)) {
                    ansectorLocked = true;
                }
                return nodeLeft;
            }
            TreeNode* nodeRight = findNode(root->right, val, ansectorLocked);
            if(nodeRight) {
                if(!ansectorLocked && hash.count(root)) {
                    ansectorLocked = true;
                }
                return nodeRight;
            }
            return nullptr;

        }
        TreeNode* findNode(TreeNode* root, int val){
            if(!root) {
                return nullptr;
            }
            if(root->val == val) {
                return root;
            }
            TreeNode* nodeLeft = findNode(root->left, val);
            if(nodeLeft) {
                return nodeLeft;
            }
            TreeNode* nodeRight = findNode(root->right, val);
            return nodeRight;
        }
};

//LockingTree::LockingTree(vector<int> &arr) {
//    int n = arr.size();
//    if(n == 0) 
//        return;
//    TreeNode* newNode = new TreeNode(arr[0]);
//    queue<TreeNode*>q;
//    root = newNode;
//    q.push(root);
//    for(int i = 0; i < n; i++){ 
//        TreeNode* parent = nullptr;
//        if(!q.empty()) {
//            parent = q.front();
//            q.pop();
//        }
//        if(parent) {
//            int l = 2 * i;
//            if(l < n) {
//                parent->left = new TreeNode(arr[l]);
//                q.push(parent->left);
//            }
//            int r = 2 * i + 1;
//            if(r < n) {
//                parent->right = new TreeNode(arr[r]);
//                q.push(parent->right);
//            }
//        }
//    }
//}
//
//TreeNode* findNode(TreeNode* root, int val) {
//    if(!root) {
//        return nullptr;
//    }
//    if(root->val == val) {
//        return root;
//    }
//    TreeNode* nodeLeft =  findNode(root->left, val);
//    if(nodeLeft) {
//        return nodeLeft;
//    }
//    TreeNode* nodeRight =  findNode(root->right, val);
//    return nodeRight;
//}
//
//bool LockingTree::lock(int num, int user) {
//    TreeNode* node = findNode(root, num);
//    return hash.count(node)? true : false;
//}

//bool LockingTree::unlock(int num, int user) {
//    TreeNode* node = findNode(root, num);
//    auto it = hash.find(node);
//    if(it != hash.end() && it->second == user) {
//        hash.erase(it);
//        return true;
//    }
//    return false;
//}
//
