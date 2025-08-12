#include<iostream>
#include<cstdlib>
using namespace std;
                                    //decimal to binary
int decToBinary(int decNum){
    int rem,pow =1,ans=0;

    while(decNum>0){
        rem = decNum%2;
        decNum/=2;

        ans+= rem*pow;
        pow*=10;
    }
    cout<<ans<<endl;
    return ans; //Binary Form
}
                                    //binary to decimal
int BinaryToDec(int BinNum){
    int rem,pow = 1,ans =0;
    while (BinNum>0){
        rem = BinNum%10;
        ans += rem*pow;

        BinNum /= 10;
        pow*=2;

    }
    cout<<ans<<endl;
    return ans;
}

int main(){
    system("cls");

    decToBinary(5);
    BinaryToDec(101);
   
    return 0;
}