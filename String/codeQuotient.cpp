#include "iostream"
#include "string"

class String {
public:

    static void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }

    static void reverse(string &str, int i, int j){
        while(i < j){
            String::swap(str.at(i++), str.at(j--));
        }
    }
    static int length(char *str) {
        int i = 0;
        while(str[i] != '\0') i++;
        return i;
    }

    static int strcmp(string str1, string str2) {

        int i = 0;
        int j = 0;
        while(i < str1.length() && j < str2.length()) {
            if(str1[i] != str2[j])
                return str1[i] - str2[j];
            i++; j++;
        }
        if(i == str1.length() && j == str2.length())
            return 0;
        if(i == str1.length())
            return -str2[j];
        return str1[i - 1];
    }

    static void strcatCode(char* str1, char* str2) {
        int i = 0;
        int j = 0;
        
        while (str1[i] != '\0') i++;
        while(str2[j] != '\0') str1[i + j] = str2[j++];
        str1[i + j] = '\0';
            
    }
    
    static bool isUniqueChars(string str){
        int *freq = new int['z' + 1];
        for (int i = 0; i < 'z' + 1; i++) {
            freq[i] = 0;
        }
        for (int i = 0; i < str.length(); i++) {
            freq[str[i]] += 1;
        }
        for (int i = 0; i < str.length(); i++) {
            if(freq[str[i]] > 1)
                return false;
        }
        delete[] freq;
        return true;
    }

    static bool isPalindrome(string str){
        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            if(str.at(i++) != str.at(j--))
                return false;
        }
        return true;
    }

    static void reverseString(string &str) {
        int i = 0;
        int j = str.length() - 1;

        while(i < j){
            String::swap(str.at(i++), str(j--));
        }
    }

    static int countWords(string str) {
        int i = 0;
        int count = 0;
        int spaces = 0;
        while(str[i] != '\0') {
            if(str[i] == ' ') spaces++;
            if(i != 0 && str[i] == ' ' && str[i - 1] != ' ')
                count++;
            i++;
        }
        return spaces == str.length() ? 0 : count + 1;
    }
    
    static void revWordsString(string str) {
       int x = 0;
       int i = 0;
       while(i <= str.length()) {
           if(i == str.length()){
               String::reverse(str, x, i - 1);
               break;
           }
           if(str.at(i) == ' '){
               String::reverse(str, x, i - 1);
               while(str.at(i) == ' ') i++;
               x = i;
               continue;
           }
           i++;
       }
       std::cout << str; 
    }
    }
};


int main (int argc, char *argv[]) {
    string *arr = new string[argc - 1];

    for (int i = 1; i < argc; i++) {
       for(int j = 0; argv[i][j] != '\0'; j++) {
           arr[i - 1] +=  argv[i][j]; 
       }
     std::cout << arr[i-1] << "\n";  
    }
    return 0;
}
