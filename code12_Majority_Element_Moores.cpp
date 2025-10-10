#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;
 
//Brute Force Approach -- Majority Element --
                // The majority element is meant to occur more than n/2 times

int mElem(vector <int>&arr){

    int n = arr.size();
    
    for(int val : arr){
        int freq = 0;

        for(int el : arr){
            if(val == el){
                freq++;
            }
        }
        if(freq >n/2){
            return val;
        }

    }
    return -1;
}

//Optimized Approach

int mElem2(vector<int>&arr){
    int n = arr.size();

    // Sortring the Array
    sort(arr.begin(),arr.end());

    //freq Count
    int freq = 1;
    int ans = arr[0];
    
    //Printing Sorted Array
    for(int i = 0;i<n;i++){
         cout<<arr[i]<<", ";
    }

    for(int i=1;i<n;i++){
        if(arr[i] == arr[i-1]){
            freq++;
        } else{
            freq = 1;
            ans = arr[i];
        }
        if(freq > n/2){
            return ans;
        }
    }
    return ans;

}

// ORRRRRRR   after sorting the arr the majority element will be at the centre(n/2) of the sorted arr


//Moore's Voting Algorithm 

int mooreElement(vector <int>& arr){
    int n = arr.size();

    int freq = 0;
    int ans = 0;

    for(int i = 0;i<n;i++){
        if(freq == 0){
            ans = arr[i];
        }
        if(ans == arr[i]){
            freq++;
        }
        else{
            freq --;
        }
    }

//If Majority Element don't exist then 

    int count =0;
    for(int val: arr){
        if(val == ans){
            count ++;
        }
    }

    if(count > n/2) return ans;
    else return -1;
}


int main(){
system("cls");

vector <int> arr1 = {4,4,4,4,4,2,2,1,1};
vector <int> arr2 = {2,2,1,1,1,2,2};


//Calling BruteForce
int ans = mElem(arr1);
cout<<ans<<endl;

//Calling Optimized
int ans2 = mElem2(arr1);
cout<<endl<<ans2<<endl;

//Calling Moore's Approach

int ans3 = mooreElement(arr2);
cout<<ans3<<endl;

return 0;
}