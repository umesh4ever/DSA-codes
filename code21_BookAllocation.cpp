#include<iostream>
#include<cstdlib>
#include<vector>

 
using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxAllowedPages){
    
    int stu = 1, pages = 0;

    for(int i = 0; i<n;i++){
        if(arr[i] > maxAllowedPages){
            return false;
        }
        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }else{
            stu++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
}
 
int bookAllocation(vector<int> &arr,int m){

    int n = arr.size();
    if(m>n){
        return -1;
    }

    int sumOfAllPages;

    for(int i = 0;i<n;i++){
        sumOfAllPages = arr[i];
    }
    
    int ans = -1;                 //don't know why , we could have put 0 instead
    int st = 0, end = sumOfAllPages;        //Range for possible ans

    while(st <= end){
        int mid = st + (mid - st)/2;
        if(isValid(arr,n,m,mid)){                       //go to
            ans = mid;
            end = mid -1; 
        }else{
            st = mid + 1;
        }
    }

    return ans;
}
int main(){
system("cls");
 
vector<int> arr = {2,1,3,4};
int m = 2;
cout<<"Min possible max no. of pages allocated is : "<<bookAllocation(arr,m)<<endl;
return 0;
}