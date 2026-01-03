#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

//printing the array
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
//Merge Sorted Array
void mergeSortedArray(vector<int> &nums1,int m,vector<int> &nums2, int n){
    int idx = m+n-1;
    int i = m-1;
    int j = n-1;

    while(i>=0 && j>=0){
        if(nums1[i] >= nums2[j]){
            nums1[idx] = nums1[i];
            idx--, i--;
        }
        else if(nums1[i] <= nums2[j]){
            nums1[idx] = nums2[j];
            idx--,j--;
        }
    }
    //if i gets <0
    while(j>=0){
        nums1[idx] = nums2[j];
        idx--,j--;
    }
}

int main(){
system("cls");

//Calling
vector<int> arr1 = {1,3,9,0,0,0};
vector<int> arr2 = {1,5,6};
mergeSortedArray(arr1,3,arr2,3);
//Printing
printArray(arr1);
 
return 0;
}