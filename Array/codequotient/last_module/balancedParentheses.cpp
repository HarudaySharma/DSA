#include<bits/stdc++.h>
#include<stack>
using namespace std;
class balance{
    char *exp;
	public: 
  	balance(char p[]){ exp=p; }
	bool isMatchingPair(char, char);
	bool areBracketsBalanced();
};

bool balance:: isMatchingPair(char char1, char char2) {
    switch (char1) {
        case '}': return char2 == '{';
        case ']': return char2 == '[';
        case ')': return char2 == '(';
        default: return false;
    }
}  

bool closeBracket(char x) {
    return x == ']' || x == '}' || x == ')';
}
  
bool openBracket(char x) {
    return x == '[' || x == '{' || x == '(';
}

bool balance:: areBracketsBalanced( ) {
    stack<char>s;
    int i = 0;
    while(exp[i] != '\0') {
        if(openBracket(exp[i])) {
            s.push(exp[i]);
        }
        else if(closeBracket(exp[i])){
            if(s.empty()) {
                return false;
            }
            if(isMatchingPair(exp[i], s.top()))
                s.pop();
            else
                return false;
        }
        i++;
    }
    return s.empty();
} 

int main() { 
    char exp[100]; 
    cin>>exp;
    balance obj(exp);
    if (obj.areBracketsBalanced( )) 
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0; 
}

