#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;

    int i = st;
    int j = mid+1;

    while(i<=mid && j<=end){        //to merge in sorted fashion
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){                  //for remaining elements in left side arr
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){                  //for remaining elements in right side arr
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
    
}

void mergeSort(vector<int> & arr,int st, int end){
    if(st<end){
        int mid = st + (end - st)/2 ;

        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,st,mid,end);
    }
}
 
int main(){
system("cls");

vector<int> arr = {4,2,3,5,1};

mergeSort(arr,0,arr.size()-1);

for(int val:arr){
    cout<<val<<" ";
}
return 0;
}