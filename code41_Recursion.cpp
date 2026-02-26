#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;
 
//n factorial
int fact(int n){
    if(n==1){       //Base case (function ends here)
        return 1;
    }

    return n * fact(n-1);
}

int sum(int n){
    if(n==1){
        return 1;
    }
    return n + sum(n-1);
}

int main(){
system("cls");
    
cout<<fact(4);
cout<<endl;
cout<<sum(4);

return 0;
}