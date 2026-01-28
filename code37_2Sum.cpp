#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<unordered_set>
 
using namespace std;

vector<int> twoSum(vector<int> &arr,int tar){
    unordered_map<int,int> m;
    int n = arr.size();

    vector<int> ans;

    for(int i=0;i<n;i++){
        int first = arr[i];
        int second = tar - first;
        
        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            return ans;
        }else{
            m[first] = i;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return ans;
}
 
vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid){
    unordered_set<int> s;
    int n = grid.size();

    int a,b;
    int actualSum = 0;
    int expectedSum = 0;

    vector<int> ans;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actualSum += grid[i][j];

            if(s.find(grid[i][j]) != s.end() ){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expectedSum = (n*n*(n*n+1)) / 2;
    
    b = expectedSum - actualSum + a;
    ans.push_back(b);

    cout<<ans[0]<<" "<<ans[1]<<endl;
    return ans;
}

int findDuplicate(vector<int> & arr){
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);

    slow = arr[0];

    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main(){
system("cls");

vector<int> vec1 = {2,5,11,7};
int target = 9;

// twoSum(vec1,target);

//missing and repeating 
vector<vector<int>> grid ={ {9,1,7},{8,9,2},{3,4,6}};
// findMissingAndRepeatedValues(grid);

vector<int> vec2 = {3,1,2,5,2,4};
cout<<"Duplicate: "<<findDuplicate(vec2)<<endl;
 
return 0;
}