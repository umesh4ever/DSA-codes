#include<iostream>
#include<cstdlib>
 
using namespace std;
 
double powXN(double x, int n){
    // Corner cases below
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n%2 == 0) return 1.0;
    if(x == -1 && n%2 != 0) return -1.0;
    
    long power = n;
    if(n < 0){
        x = 1/x ;
        power = - power;    // we are using the binary form of the power n
    }
    
    double ans = 1;
    while(power > 0){
        if(power % 2 == 1){
            ans *= x;
        }
        x *= x;
        power /= 2;
    }
    return ans;
}


int buySell()

int main(){ 
system("cls");

cout<<powXN(5,-2);

return 0;
}