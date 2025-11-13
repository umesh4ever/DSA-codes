#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

// binary search is used when the given data is SORTED and 

int searchArrTarget(vector<int> &arr , int tar){
    int n = arr.size();
    int st  = 0;
    int end = n - 1;

    
    while(st <= end){
        int mid = st + (end - st)/2 ;          // used instead of (st + end)/2
        
        if(arr[mid] == tar){ 
            return mid;
        }
        if(arr[mid] > tar){
            end = mid -1;
        }else{
            st = mid + 1;
        }
    }
    return -1;

}
 
int main(){
system("cls");

vector<int> arr1 = {-1,0,2,4,6,8,9};
int target = 66;

cout<<searchArrTarget( arr1,target)<<endl;

return 0;
}