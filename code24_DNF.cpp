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

//Sorting the 0s,1s and 2s with count method(O(n) but has 2 passes) 
void sort_0_1_2(vector<int> &arr){
    int n = arr.size();
    int count0 = 0,count1 = 0,count2 = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            count0++ ;
        }
        else if(arr[i] == 1){
            count1++ ;
        }
        else if(arr[i] == 2){
            count2++ ;
        }
    }
    int idx = 0;
    for(int i = 0;i<count0;i++){
        arr[idx] = 0;
        idx++;
    }
    for(int i = 0;i<count1;i++){
        arr[idx++] = 1;     //idx++ in same line (But it increments post arr[idx] is set)
    }
    for(int i = 0;i<count2;i++){
        arr[idx++] = 2;
    }
}

//DNF
void dutchNationalFlag(vector<int> &arr){
    int n = arr.size();
    int l = 0,m = 0 ,h = n-1;

    while(m <= h){
        if(arr[m] == 0){
            swap(arr[m],arr[l]);
            m++;
            l++;
        }else if(arr[m] == 1){
            m++;
        }else if(arr[m] == 2){
            swap(arr[m],arr[h]);
            h--;
        }
    }
}


int main(){
system("cls");

//Calling the 2-Pass O(n) method
vector<int> nums = {2,0,2,1,1,0};
sort_0_1_2(nums);
printArray(nums);

//Calling the DNF method
vector<int> nums2 = {2,2,0,2,1,1,0};
dutchNationalFlag(nums2);
printArray(nums2);
return 0;
}