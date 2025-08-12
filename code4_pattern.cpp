#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
system("cls");


int n=9;
// // floyd's triangle pattern

// int num=1;

// for(int i=0;i<n;i++){

//     for(int j=0;j<i+1;j++){
//         cout<<num;
//         num++;
//     }

//     cout<<endl;
// }

//inverted triangle
// for(int i=0;i<n;i++){

//     for(int j=0;j<i;j++){
//         cout<<" ";
//     }

//     for(int j=0;j<n-i;j++){
//         cout<<(i+1);
//     }
//     cout<<endl;
// }

// pyramid
for(int i=0;i<n;i++){
    for(int j=0;j<(n-i-1);j++){
        cout<<" ";
    }
    for(int j=1;j<=(i+1);j++){
        cout<<j;
    }
    for(int j=i;j>0;j--){
        cout<<j;
    }
    cout<<endl;
}  

//hollow diamond pattern


return 0;
}