#include<iostream>
#include<cstdlib>
 
using namespace std;

//check if alpha numeric or not
bool isAlphaNum(char &ch){
    if((ch >='0' && ch<='9') || (tolower(ch) >='a' && tolower(ch) <='z')){
        return true;
    }
    return false;
}
//you can also use {isalnum(ch)}

//check valid palindrome
bool isValidPalindrome(string &s){
    int st = 0, end = s.length() - 1;
    while(st<end){
        if(!isAlphaNum(s[st])) {
            st++ ; continue;
        }
        if(!isalnum(s[end])) {
            end-- ; continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            return false;
        }
        st++,end--;

    }
    return true;
}


//Remove all occurrences
string removeAllOccurrences(string &s ,string &part){
    while(s.length() >0 && s.find(part) <= s.length()){
        s.erase(s.find(part),part.length());
    }
    //if string left empty
    if(s.length() == 0){
        cout<<"String became null(0)"<<endl;
    return s;
    }
    return s;
}

int main(){
system("cls");
 
string s = "Ac3?e3&ca";
cout<<isValidPalindrome(s)<<endl;
// string s2 = "daabcbaabcbc";
string s2 = "abc";
string part = "abc";
cout<<removeAllOccurrences(s2,part);

return 0;
}