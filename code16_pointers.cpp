#include<iostream>
#include<cstdlib>
 
using namespace std;



int main(){
system("cls");
 
int a = 5;
int* ptr = &a;
cout<<"a ka ptr :"<<ptr<<endl; //ptr value(address of a)

//parent pointer
int** parptr = &ptr;

//Dereferencing
cout<<"value at ptr[ie. a] : "<<*(ptr)<<endl;
cout<<"value at ptr[adress of a] :"<<*(parptr)<<endl;  //value stored in ptr
cout<<"a via ** double dereference :"<<**(parptr)<<endl; //value stored in a(via ptr)


//NULL pointer
int* nullPtr = NULL;
cout<<"NULL pointer :"<<nullPtr<<endl; //value will be 0

//pass by reference


//array pointer
int arr[] = {1,2,3,4,5};    //array itself is a pointer

cout<<"arr[ptr itself] :"<<*(arr)<<endl;  //gives the 1st value stored at that arr[pinter] 


//pointer arithmetic

//increment OR decrement
int b = 2;
int* bKaPtr = &b;

cout<<"b ka ptr :"<<bKaPtr<<endl;
bKaPtr ++;
cout<<"incremented b ka ptr :"<<bKaPtr<<endl;

//addition OR subtraction 
bKaPtr = bKaPtr + 3;  // adding 1 adds 4 bytes [3*4 = 12]
cout<<"added 3 to b ka ptr :"<<bKaPtr<<endl;         // used in array to print elements

//subtracting pointers
int c = 6;
int d = 9;
int* cKaPtr = &c; 
int* dKaPtr = &d; 

cout<<"c ka ptr :"<<cKaPtr<<endl;
cout<<"d ka ptr :"<<dKaPtr<<endl;
cout<<"cptr - dptr :"<<cKaPtr - dKaPtr<<endl; // i don't know whats happening here

//comparison operation
cout<<(cKaPtr == dKaPtr ? "same" : "NOT same");


return 0;
}