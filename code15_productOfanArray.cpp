#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

//                                    Product of an array except itself
// Brute Force 
vector <int> arrayProduct(vector <int>&arr ){
    int n = arr.size();
    vector <int> ans1(n,1);
    for(int i = 0; i<n;i++){
        int prod = 1;
        for(int j = 0; j<n;j++){
            if(i != j){
                prod *= arr[j];
            }
            ans1[i] = prod;
        }
    }    
    return ans1 ;
}

// Optimal Approach
vector <int> arrayProductOP(vector <int>&arr ){
    int n = arr.size();
    // To calculate prefix
    vector <int> prefix(n,1);
    for(int i = 1; i<n;i++){
        prefix[i] = prefix[i-1] * arr[i-1];
        
    }
    // To calculate suffix
    vector <int> suffix(n,1);
    for(int i = n-2; i >= 0;i--){
        suffix[i] = suffix[i+1] * arr[i+1];
    }
    // To calculate answer
    vector <int> ans2(n,1);   
    for(int i = 0; i<n;i++){
        ans2[i] = prefix[i] * suffix[i]; 
    }

    return ans2;

}

//Optimal Approach with better space Complexity
vector <int> arrayProductOP2(vector <int>&arr ){
    int n = arr.size();

    vector <int> ans3(n,1);  
    
    //calculate prefix and multiplying to its corresponding arr
    for(int i = 1; i<n;i++){
        ans3[i] = ans3[i-1] * arr[i-1];    
    }
    //calculate suffix and multiplying to its corresponding arr
    int suffix =1;
    for(int i = n-2; i >= 0;i--){
        suffix *= arr[i+1];
        ans3[i] *= suffix ;
    }

    return ans3;

}


int main(){
system("cls");

vector <int> arr = {1,2,3,4};
//Calling Brute Force 
vector <int> ans1 = arrayProduct(arr);
for (int x : ans1 ) cout<<x <<" ";

cout<<endl;

//Calling Brute Force 
vector <int> ans2 = arrayProductOP(arr);
for (int x : ans2 ) cout<<x <<" ";
cout<<endl;

//Calling Brute Force 
vector <int> ans3 = arrayProductOP2(arr);
for (int x : ans3 ) cout<<x <<" ";
 
return 0;
}