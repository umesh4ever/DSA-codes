#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

int partition(vector<int> &arr, int st, int end){
    
    int idx = st-1;
    int pivot = arr[end];

    for(int i = st;i<end;i++){
        if(arr[i] <= arr[end]){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }

    idx++;
    swap(arr[end],arr[idx]);
    return idx;

}

void quickSort(vector<int> &arr, int st, int end){
    if(st<end){
        int pivIdx = partition(arr,st,end);

        quickSort(arr,st,pivIdx-1); //left
        quickSort(arr,pivIdx+1,end); //right
    }
}

int main(){
system("cls");

vector<int> arr = {5,2,6,4,1,3};
quickSort(arr,0,arr.size()-1);


//printing sorted array
for(int val:arr){
    cout<<val<<" ";
}
cout<<endl;
 
return 0;
}