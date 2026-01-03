#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;

//printing the array
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
 
void nextPermutation(vector<int> &nums){
    int piv = -1;
    int n = nums.size();
    //Finding the pivot
    for(int i = n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            piv = i;
            break;
        }
    }
    //if NO NextPermutation exists
    if(piv == -1){
        reverse(nums.begin(),nums.end());
        return;
    }

    for(int i = n-1;i > piv;i--){
        if(nums[i] > nums[piv]){
            swap(nums[piv],nums[i]);
            break;
        }
    }
    int i = piv+1,j = n-1;
    while(i<=j){
        swap(nums[i],nums[j]);
        i++,j--;
    }
}

int main(){
system("cls");

//Calling
vector<int> arr1 = {1,2,3,6,5,4};
nextPermutation(arr1);
//Printing
printArray(arr1);
 
return 0;
}