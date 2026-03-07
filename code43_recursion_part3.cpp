#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

//subset of an array
void subset(vector<vector<int>> & allSubsets, vector<int> & arr,vector<int> & ans, int i ){
    if(i == arr.size()){
        allSubsets.push_back(ans);
        return;
    }

    //include
    ans.push_back(arr[i]);
    subset(allSubsets,arr,ans,i+1);

    ans.pop_back();
    //exclude
    subset(allSubsets,arr,ans,i+1);
}


//Subset II

void subsetsWithDup(vector<vector<int>> & allSubsets, vector<int> & arr,vector<int> & set, int i ){

    if(i == arr.size()){
        allSubsets.push_back(set);
        return;    
    }

    //including
    set.push_back(arr[i]);
    subsetsWithDup(allSubsets,arr,set,i+1);

    set.pop_back();

    //exluding
    int idx = i+1;

    while( idx < arr.size() && arr[idx] == arr[idx-1]){
        idx++;
    }
    subsetsWithDup(allSubsets,arr,set,idx);
}


int main(){
system("cls");



vector<int> arr = {1,2,3};      //question array
vector<int> ans ;       //single subsets here
vector<vector<int>> allSubsets;     //all subsets in this 2d array
// subset(allSubsets,arr,ans,0);

//Printing the subsets
// for(vector<int> vec : allSubsets){
//     for(int val : vec){
//         cout<<val<<" ";
//     }
//     cout<<endl;
// }




//Subset with duplicates
vector<int> arr2 = {1,2,2};      //question array
vector<int> ans2 ;       //single subsets here
vector<vector<int>> allSubsets2;     //all subsets in this 2d array
//Need to sort the array first
subsetsWithDup(allSubsets2,arr2,ans2,0);

//Printing the subsets
for(vector<int> vec : allSubsets2){
    for(int val : vec){
        cout<<val<<" ";
    }
    cout<<endl;
}
 
return 0;
}