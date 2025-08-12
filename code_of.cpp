#include<iostream>
#include<cstdlib>
#include<climits>

 

using namespace std;

//to calc. sum of an array
int sum(int arr1[], int size ){
    int sum =0;
    
    for(int i = 0; i<size; i++){
        sum += arr1[i]; 
    }
    cout<<sum<<endl;
    return sum;
}


//to calc. product of array
int product(int arr2[], int size2 ){
    int pro =1;
    
    for(int i = 0; i<size2; i++){
        pro *= arr2[i]; 
    }
    cout<<pro<<endl;
    return pro;
}


int small = INT_MAX;
int large = INT_MIN;

//swap min and max nums of an array

int swap(int arr3[], int   size3){
 
    for(int i=0;i<size3;i++){
        
        small = min(small, arr3[i]);
        large = max(large, arr3[i]);

    }
    cout<<"smallest: "<<small<<endl;
    cout<<"largest: "<<large<<endl;

    for(int i=0;i<size3;i++){
        if(arr3[i] == small){
           for(int j=0;j<size3;j++){
                if(arr3[j] == large){
                    swap(arr3[i],arr3[j]);
                        cout<<"Swapped array is: ";
                     for(int i=0;i<size3;i++){
                        cout<<arr3[i]<<" ";
                    }
                    exit(0);
                }
            }
        }
        
    }
   
    
}
// array is swapped 

//unique value of an array

int unique(int arr4[],int size4){
    for(int i=0; i<size4;i++){
        
    }
}


int main(){
system("cls");




int arr1[] = {1,2,3,4,5};
int size = 5;
 
int arr2[] = {3,4,5};
int size2 = 3;
 
int arr3[] = {2,4,6,8};
int size3 = 4;


sum(arr1,size);
product(arr2,size2);
swap(arr3,size3);

return 0;
}

