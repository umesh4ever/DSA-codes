#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 

using namespace std;

bool isValid(vector<int> &arr, int c,int n, int allowedMaxVal){
    int cow = 1, lastStallPos = arr[0] ;

    for(int i = 1;i<n;i++){
        if((arr[i]-lastStallPos) >= allowedMaxVal){
            cow++;
            lastStallPos = arr[i];
        }
        if(cow == c){
            return true;
        }
    }
    return false;
}

int aggressiveCow(vector<int> &arr, int c){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    
    int ans = 1;
    int st = arr[0] , end = arr[n-1] - arr[0];

    while(st<=end){
        int mid = st + (end-st)/2;

        if(isValid(arr, c,n, mid)){
            ans = mid;
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }

    return ans;
}



int main(){
system("cls");
 
vector<int> arr = {2,12,11,3,26,7};
int c = 5;
cout<<aggressiveCow(arr,c);

return 0;
}