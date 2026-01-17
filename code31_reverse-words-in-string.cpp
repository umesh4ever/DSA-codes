#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;

string reverseWordsInString(string &s){

    int n = s.length();
    string ans = "";
    //reverse the whole string first
    reverse(s.begin(),s.end());

    for(int i = 0;i<n;i++){

        string word = "";
        //add letters to the word excluding the spaces
        while(i<n && s[i] != ' '){
            word += s[i];
            i++;
        }
        //reverse the word
        reverse(word.begin(),word.end());
        //add thr word to ans only if the word is not empty
        if(word.length() > 0){
            ans += " " + word;
        }
    }
    //return the string excluding the starting space
    return ans.substr(1);
}
 
int main(){
system("cls");
string s1 = "hamma hamma ramma ramma";
cout<<reverseWordsInString(s1);
 
return 0;
}