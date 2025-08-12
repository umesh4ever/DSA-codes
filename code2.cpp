#include<iostream>
using namespace std;

int main(){

     //sum of n odd no.s

    // int n=5,sum=0;
    // int i=1;

    // while(i<=n){
    //     if(i%2!=0){
    //     sum = sum +i;
    //     }
    //     i++;
    // }
    //  cout<<sum<<" ";

    //if a no. is prime or not

    int n=22;
    bool isPrime = true;
    
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            isPrime = false;
            break;
        }
    }

    if(isPrime == true){
        cout<<"prime"<<endl;
    }

    else{
        cout<<"non-prime"<<endl;
    }
    
    return 0;
}