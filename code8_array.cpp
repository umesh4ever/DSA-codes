#include <iostream>
#include<cstdlib>   

using namespace std;


    int reverseArr(int revArr[], int sizeOf_revArr){
        int start = 0, end = sizeOf_revArr -1;

        while(start <= end){
            swap(revArr[start],revArr[end]);
            start++;
            end--;
        }
       
    }
    



int main(){
    system("cls");
    cout<<"The Result Starts From Here"<<endl;


    // int marks[5];
    // int sizeOf_marks = sizeof(marks) / sizeof(int);  //array size 

    // // To input array elements 
    // cout<<"Marks are : ";
    // for(int i =0; i<sizeOf_marks;i++){
    //     cin>> marks[i];
    // }
    // // For printing array elements 
    // cout<<"Marks are : ";
    // for(int i = 0;i<sizeOf_marks;i++){
    //     cout<<marks[i]<<", ";
    // }

// Smallest And Largest element in an array 

    int num[] = {5,15,-33, 22,1,-15,-24};
    int sizeOf_num =  sizeof(num) / sizeof(int);

    int smallest = INT16_MAX ;
    int largest = INT16_MIN ;

    int small_index;
    int large_index;

    for(int i =0;i<sizeOf_num;i++){
        smallest = min(num[i],smallest);
        largest = max(num[i],largest);
        
    }
    cout<<"smallest no. is : "<<smallest<<endl;
    cout<<"largest no. is : "<<largest<<endl;

    for(int i =0;i<sizeOf_num;i++){
        if(smallest == num[i]){
            small_index = i;
        }
        
        if(largest == num[i]){
            large_index = i;
        }
    }
    // cout<<"index of smallest no. is : "<<small_index<<endl;
    // cout<<"index of largest no. is : "<<large_index<<endl;



// Linear Search from here on


    // int linearSearch(int arr[], int sizeOf_arr,int searchTarget){
    //     for(int i=0; i<sizeOf_arr; i++){
    //         if(arr[i] == searchTarget){
    //             cout<<searchTarget<< " is at index " <<i<<endl;
    //             return i;
    //         }        
    //     }
    //     cout<<"No. "<< searchTarget<<" not found"; 
    //     return -1;
    // }

    



//reversing an array





    


// Linear Search from here on


    // int arr[] = {4,7,8,1,2,5};
    // int sizeOf_arr = sizeof(arr) / sizeof(int);

    // int searchTarget = 8; //no to search in the array and find it's index

    // linearSearch(arr, sizeOf_arr,searchTarget );



//Reversing an array


    int revArr[] = {1,2,3,4,5};
    int sizeOf_revArr = sizeof(revArr) / sizeof(int);

    
    reverseArr(revArr,sizeOf_revArr);
    
    cout<<"Reverse array is : ";
       for(int i=0;i<sizeOf_revArr;i++){
       cout<<revArr[i]<<" ";
       }


    return 0;
}

