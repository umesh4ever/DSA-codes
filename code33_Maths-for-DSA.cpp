#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
 
using namespace std;

//check if n is prime
string isItPrime(int n){
    for(int i = 2;i<n;i++){
        if(n%2 == 0){
            return "NOT prime";
        }
    }
    return "prime";
}
 
//sieve of Eratosthenes
int primeCount(int n){
    vector<bool> isPrime(n+1,true);
    int count = 0;

    for(int i = 2; i<= n; i++){
        if(isPrime[i]){
            count++;
            for(int j = 2*i ;j<=n; j=j+i ){
                isPrime[j] = false;
            }
        }
    }
    return count;
}

//Digits in a number
int printDigit(int n){
    int count = 0;
    while (n != 0){
        int dig = n%10;
        cout<<dig<<endl;
        count++;
        n /= 10;
    }
    return count;
    
}


//Armstrong number
bool isArmstrong(int n){
    int copyN = n;
    int sumOfCubes = 0;
    while(copyN !=0){
        int dig = copyN%10;
        sumOfCubes += (dig*dig*dig);
        copyN /= 10;  
    }
    return (n == sumOfCubes);
}

//GCD(greatest common divisor)
int gcd(int a,int b){
    int gcd;

    for(int i = 1;i<min(a,b);i++){
        if(a%i == 0 && b%i == 0 ){
            gcd = i;
        }
    }
    return gcd;
}

//GCD using Euclid's Algorithm
int euclidGCD(int a,int b){
   
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }else{
            b = b%a;
        }
    }
    if (a==0) return b;
    return a;
}

//LCM(lowest common multiple)
int lcm(int a,int b){
    int gcd = euclidGCD(a,b);
    return (a*b)/gcd;
}

//Reverse a number
int reverseNumber(int n){
    
    int revN=0;

    while(n != 0){
        int dig = n%10;
        //add a condition to check if the revN exceeds INT_MAX or INT_MIN
        if(revN < INT16_MIN/10 && revN > INT16_MAX/10) return 0;
        revN = revN*10 + dig;
        n = n/10;
    }
    return revN;
}

//Palindrome number
bool palindromeNumber(int n){
    int copyN = n;
    int revN=0;

    while(n > 0){
     
        int dig = n%10;
       
        revN = revN*10 + dig;
        n = n/10;
    }
    return revN == copyN;
}



int main(){
system("cls");


cout<<"is it prime :"<<isItPrime(41)<<endl;
cout<<"total primes b/w :"<<primeCount(23)<<endl;
cout<<"accessing the digits in no. :"<<printDigit(3568)<<endl;
cout<<"is it armstrong :"<<isArmstrong(13)<<endl;
cout<<"gcd via basic :"<<gcd(20,28)<<endl;
cout<<"gcd using Euclid's Algorithm :"<<gcd(20,28)<<endl;
cout<<"LCM of a and b:"<<lcm(20,28)<<endl;
cout<<"Reversed number:"<<reverseNumber(123456789)<<endl;
cout<<"is palindrome number:"<<palindromeNumber(323)<<endl;


return 0;
}