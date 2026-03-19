#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>
 
using namespace std;

set<vector<int>> s;

void helper(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin){

    if(idx == arr.size() || tar <0){
        return;
    }

    if(tar == 0){
        if(s.find(combin) == s.end()){
            ans.push_back(combin);
            s.insert(combin);
        }
        
        return;
    }

    combin.push_back(arr[idx]);
    //single incl
    helper(arr, idx+1, tar-arr[idx], ans, combin);  
    //multiple incl
    helper(arr, idx, tar-arr[idx], ans, combin);  

    //backtracking
    combin.pop_back();
    //excluding
    helper(arr, idx+1, tar, ans, combin);  //excluding
    

}

int main(){
system("cls");

vector<int> arr = {2,3,5};
int tar = 8;
vector<vector<int>> ans;
vector<int> combin;

helper(arr,0,tar,ans,combin);

//printing
for(vector<int> val : ans){
    for(int v : val){
        cout<<v<<" ";
    }
    cout<<endl;
}
 
return 0;
}