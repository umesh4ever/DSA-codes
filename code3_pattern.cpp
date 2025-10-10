 #include<iostream>
 #include<cstdlib>
using namespace std;

int main(){
system("cls");


    int n=4;
    // char ch='A';

    // for(int i=0;i<n;i++){

    //     for(int j=0;j<n;j++){
    //         cout<<ch<<" ";
    //         ch++;
    //     }
    //     cout<<endl;
    // }

    //triangle pattern

   for(int i=0;i<n;i++){
     for(int j=0;j<i+1;j++){
         cout<<"* ";
     }
     cout<<endl;
   }

//  for(int i=0;i<n;i++){

//     for(int j=0;j<i+1;j++){
//         cout<<(i+1)<<" ";
//     }
//     cout<<endl;
//  }


return 0;
}