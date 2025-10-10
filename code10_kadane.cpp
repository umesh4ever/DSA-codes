#include<iostream>
#include<cstdlib>
 
using namespace std;
 
int main(){
system("cls");
    int arr[] = {1,2,3,4,5};
    int n =5 ;

//printing subArrays of an array

    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }

//printing max sub array sum
int arr2[] = {3,-4,5,4,-1,7,-8};
int n2 =7;
int maxsum = INT16_MIN;

for(int st=0;st<n;st++){
        int csum = 0;
        for(int end=st;end<n2;end++){
            csum +=arr[end];
            maxsum = max(csum,maxsum);
        }
    }
    cout<<"max sum is "<<maxsum;
    return maxsum;

//Kadane's algorithm



    return 0;
}