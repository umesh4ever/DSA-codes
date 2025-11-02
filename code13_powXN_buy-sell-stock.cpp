#include<iostream>
#include<cstdlib>
#include<vector>
 
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


int buyAndSellStock(vector<int>&prices){
    int n = prices.size();
    
    int maxProfit = 0;
    int bestBuy = prices[0];

    for(int i = 1;i<n;i++){
        if(prices[i] > bestBuy){
            maxProfit = max(prices[i] - bestBuy , maxProfit);
        }
        bestBuy = min(bestBuy,prices[i]);
    }
    if(maxProfit == 0){
        return 0;
    }else{
        return maxProfit;
    }
}

int main(){ 
system("cls");

cout<<"X^N is "<<powXN(5,-2)<<endl;

vector <int> prices = {7,1,5,3,6,4};
cout<<"Max Possible Profit is "<<buyAndSellStock(prices);
return 0;
}