#include<iostream>
#include<cstdlib>
#include<vector>
// #include<algorithm>
 
using namespace std;

void perms(vector<int> & arr,int idx,vector<vector<int>> &ans){

    if(idx == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i=idx ; i<arr.size();i++){
        swap(arr[idx],arr[i]);
        perms(arr,idx+1,ans);

        swap(arr[idx],arr[i]);
    }
}

int main(){
system("cls");
 
return 0;
}