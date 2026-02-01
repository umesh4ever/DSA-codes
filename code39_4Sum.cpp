#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;
 
vector<vector<int>> fourSum(vector<int> & nums, int tar){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());

    for(int i=0;i<n;i++){
        if ( i > 0 && nums[i] == nums[i-1]) continue;
        
        for(int j=i+1;j<n;){      

            int p = j+1;
            int q = n-1;
            
            while(p<q){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];

                if(sum < tar){
                    p++;
                }else if(sum > tar){
                    q--;
                }else{
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;q--;

                    while(p < q && nums[p] == nums[q]) p++;
                }
            }
            j++;
            while(j < n && nums[j] == nums[j-1]) j++;
        }
    }
    return ans;
}

int main(){
system("cls");

vector<int> nums = {1,0,-1,0,-2,2};
int target = 0;
fourSum(nums,target);
 
return 0;
}