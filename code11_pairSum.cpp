#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

// Brute Force Approach -- Pair Sum --

vector <int> pairSum(vector <int> &nums,int target){
    int n = nums.size();

    vector <int> ans;

   for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

//More Optimized Approach     -- Sorted Array --

vector <int> pairSum2(vector <int> &nums,int target){
    int n = nums.size();
    vector <int> ans;


    int i = 0, j = n-1;

    while(i<j){
        int pSum = nums[i] + nums[j];
        
        if(pSum > target){
            j--;
        } else if(pSum < target){
            i++;
        } else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}

int main(){
system("cls");
 
vector <int> nums = {2,7,11,15};
int target = 26;


// vector <int> ans = pairSum(nums,target);
// cout<<ans[0]<<", "<<ans[1]<<endl;

vector <int> ans = pairSum2(nums,target);
cout<<ans[0]<<", "<<ans[1]<<endl;

return 0;
}