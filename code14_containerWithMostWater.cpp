#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;
 
//Brute Force Approach 
int containerWithMostWater(vector <int>& height){
   
    int n = height.size();
    int mw = 0;
    // cout<<height[4];
    for(int i= 0;i<n;i++){
        for(int j = i+1;j<n; j++){
           int width = j-i;
            int ht = min(height[i],height[j]);
            int area = width * ht;

            mw = max(mw,area);
        }
    }
    return mw;
}

//2 Pointer Approach
int mostWater2(vector <int>& height){
    
}

int main(){
system("cls");

vector<int> height = {1,3,5,3,4,1,2};
//calling brute force approach
int ans1 = containerWithMostWater(height);
cout<<ans1;



return 0;
}