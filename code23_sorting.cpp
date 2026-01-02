#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;


//print the sorted array
void printArr(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//bubble short
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    int isSwap = false;

    for(int i = 0; i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }

        if(!isSwap){
            return;
        }
    }
}

//Selection Sort
void selectionSort(vector<int> &arr){
    int n = arr.size();
    
    for(int i = 0;i<n-1;i++){
        int smallestIndex = i;

        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
    }
}

//Insertion Sort
void insertionSort(vector<int> &arr){
    int n = arr.size();

    for(int i = 1;i<n-1;i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev>= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

//For Descending Sorting just reverse the loop conditions

 
int main(){
system("cls");
    
    vector<int> arr1 = {4,1,5,2,3};
//bubble
    bubbleSort(arr1);
    printArr(arr1);
//selection
    selectionSort(arr1);
    printArr(arr1);
//Insertion
    insertionSort(arr1);
    printArr(arr1);

return 0;
}