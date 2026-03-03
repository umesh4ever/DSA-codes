#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

//is Array sorted
bool isArraySorted(vector<int> & arr, int n){
    if(n==0 || n==1){
        return true;
    }

    return (arr[n-1] >= arr[n-2]) && isArraySorted( arr , n-1) ;
}

//Binary search
int BinarySearch(vector<int> & arr, int tar, int st, int e){
    if(st<=e){
        int mid = st + (e-st)/2;

        if(arr[mid] == tar){
            return mid;
        }else if(arr[mid] < tar){
            return BinarySearch(arr,tar,mid+1,e);
        }else{
            return BinarySearch(arr,tar,st,mid-1);
        }
    }
    return -1; //vv Imp as we need to exit from the recursive function from all stages
}
 
int main(){
system("cls");

cout<<fib(4)<<endl;
vector<int> arr1 = {1,2,3,4,5};
cout<<isArraySorted(arr1,arr1.size())<<endl;
//Calling binary search
vector<int> arr2 = {1,2,3,8,5};
cout<<BinarySearch(arr2,8,0,arr2.size()-1)<<endl;


return 0;
}