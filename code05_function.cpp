#include<iostream>
#include<cstdlib>
using namespace std ;

// Functions in C++ WARNING:functions ahead

int min(int a,int b){
        if( a < b){
            cout<<"No."<< a<< " is min"; 
        }
        else{
            cout<<"No."<< b<< " is min"; 
        }
    }
// sum till no. N
int sumN(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        s += i;
    }
    cout<< s ;
}
// factorial of n!
int factorial(int n){
    int f=1;
    
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
    cout<<"The factorial of "<<n<<" is "<<f;
}
int sumOfDigit(int num){
    int digSum = 0;
    
    while(num>0){
        int lastDigit = num%10;
        digSum += lastDigit;

        num /= 10;
    }
    return digSum;
}

// Binomial Coefficient
int nCr(int n, int r){
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_nmr = factorial(n-r);

     int bino = fact_n/(fact_nmr*fact_r);

    //  cout<< fact_n;
    //  cout<< fact_r;
     cout<< bino;
}

// HomeWork Questions

// Q1 is prime or not
int isPrime(int n){
    bool isprime;
    for(int i = 2; i<n;i++){
        if(n%i==0){
             isprime = false;
            break;
        }else{
             isprime = true;
        }
    }
    if(isprime == true){
        // cout<<"prime";
    }else{
        // cout<<"NOT prime";
    }
    return isprime;
    
}

// Q2 prime prime no.s till n
int primeNums(int n){
    for(int i=1;i<=n;i++){
        if(isPrime(i) == true){
            cout<<i<<endl;
        }
    }
}

int main(){
    system("cls");
    cout<<"The Result Starts From Here"<<endl;



    // min(3,9);
    sumN(8);
    // factorial(9);
    
    // sumOfDigit(2356);
    // cout<<sumOfDigit(2356);

    // nCr(5,2);

    // isPrime(23);
    // cout<<isPrime(23);
    // primeNums(100);

    
    return 0;
}
