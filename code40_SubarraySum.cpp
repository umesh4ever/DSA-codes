#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
 
using namespace std;

//Brute-Force
int subarraySum(vector<int> &arr,int k){
    int n = arr.size();
    int count = 0;

    for(int i = 0; i<n; i++){
        int sum = 0;

        for(int j = i;j<n;j++){
            sum += arr[i];
            if(sum == k) count++;
        }
    }

    return count;
}

//Optimized 
int subarraySumOPTIMIZED(vector<int> &arr,int k){
    int n = arr.size();
    int count = 0;

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for(int i = 1; i<n; i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    unordered_map<int,int> m;
    for(int j = 0;j<n;j++){
        if(prefixSum[j] == k) count++;

        int val = prefixSum[j] - k;

        if(m.find(val) != m.end()){
            count += m[val];
        }
        
        if(m.find(prefixSum[j]) == m.end()){ 
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }
    return count;
}
 
int main(){
system("cls");

vector<int> arr1 = {9,4,20,3,10,5};
int k = 33;
subarraySumOPTIMIZED(arr1,k);
 
return 0;
}