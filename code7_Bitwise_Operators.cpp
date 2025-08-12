#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    system("cls");
    //Bitwise operators - AND OR XOR(either 1 or 0 will give 1 else 0 {1-1 or 00})
    int a=5,b=3;
    cout<<(a & b)<<endl;    
    cout<<(a | b)<<endl;    
    cout<<(a ^ b)<<endl;    

    //Bitwise operator - Left shift Right shift

    cout<<(5<<1)<<endl;
    cout<<(10>>1)<<endl;

    cout<<"size of int: "<<sizeof(int)<<endl;
    cout<<"size of long int: "<<sizeof(long int)<<endl;
    cout<<"size of long long int:"<<sizeof(long long int)<<endl;
    cout<<"size of short int: "<<sizeof(short int)<<endl;
    cout<<"size of signed int: "<<sizeof(signed int)<<endl;
    cout<<"size of unsigned int: "<<sizeof(unsigned int)<<endl;

    //unique no. from an array
    
    return 0;
}