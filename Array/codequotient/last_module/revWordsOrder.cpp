#include<iostream>
#include <sstream>
#include<stack>
#include <string>
using namespace std;
class Result {
    string s;
    public:
  	Result(string s1){
		s=s1;
	}
	string revWordsOrder();
};

string Result::revWordsOrder() {
    string res;
    int wordLen = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s.at(i) == ' ') {
            if(i + 1 < s.size())
                res.append(s.substr(i + 1, wordLen));
            while(i >= 0 && s.at(i) == ' ') {
                res.push_back(' ');
                i--;
            }
            i++;
            wordLen = -1;
        }
        wordLen++;
    }
    res.append(s.substr(0, wordLen));
    return res;
}
