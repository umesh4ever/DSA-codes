#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>
#include<algorithm>
 
using namespace std;
 
vector<vector<int>> threeSum(vector<int> &arr){

    int n = arr.size();
    set<vector<int>> uniqueTriplets;

    for(int i=0;i<n;i++){
        int tar = -arr[i];
        set<int> s;

        for(int j=i+1;j<n;j++){
            int third = tar - arr[j];

            if(s.find(third) != s.end()){
                vector<int> trip = {arr[i],arr[j],third};
                sort(trip.begin(),trip.end());

                uniqueTriplets.insert(trip);
            }

            s.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(),uniqueTriplets.end());   //ans here matrix array
    return ans ;
}

vector<vector<int>> threeSum2(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    

    for(int i=0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;

        int j = i+1, k = n-1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
        
            if(sum < 0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                ans.push_back({arr[i] , arr[j] , arr[k]});
                j++;k--;

                while(j<k && arr[j] == arr[j-1]) j++;
            }

        }
    }
    return ans;
}

int main(){
system("cls");

vector<int> arr = {-1,0,1,2,-1,-4};
threeSum(arr);
 
return 0;
}