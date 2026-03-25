#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;

bool isPalin(string str){
    string str2 = str;
    reverse(str.begin(),str.end());
    return str2 == str;
}

void helper(string s, vector<string> & partition ,vector<vector<string>> &ans){

    if(s.size() == 0){
        ans.push_back(partition);
        return;
    }
    

    for(int i = 0;i<s.size();i++){
        string part = s.substr(0,i+1);

        if(isPalin(part)){
            partition.push_back(part);
            helper(s.substr(i+1),partition,ans);
            partition.pop_back();
        }
    }
}
 
int main(){
system("cls");

string s = "aab";

vector<string> partition;
vector<vector<string>> ans;
helper(s,partition,ans);

//printing
for(vector<string> val : ans){
    for(string v : val){
        cout<<v<<" ";
    }
    cout<<endl;
}

return 0;
}