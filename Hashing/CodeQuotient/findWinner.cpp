#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

string inspectStrings(vector<string> words) {
// use ordered_map 
    map<string, int> hash;
    for(auto el : words) {
        auto it = hash.find(el);
        if(it != hash.end()) {
            it->second += 1;
        }
        hash.insert({el, 1});
    }
    string res = hash.begin()->first;
    int count = hash.begin()->second;
    for(auto &pair : hash) {
        if(pair.second > count){
            res = pair.first;
            count = pair.second;
        }
        else if(pair.second == count && res.compare(pair.first) < 0)  {
                res = pair.first;
            }
        }
       return res; 
}
 
int main (int argc, char *argv[]) {
    
    return 0;
}
