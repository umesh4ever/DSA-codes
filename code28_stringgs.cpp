#include<iostream>
#include<cstdlib>
#include<vector>
#include<cstring>
 
using namespace std;
 
int main(){
system("cls");
 
char str[] = {'a','b','c','\0'};
cout<<str<<endl;
// strlen need to include<cstring>
char str2[] = "umesh";
cout<<strlen(str2)<<endl;

//char cin via getline
char str3[12];
// cout<<"enter a string:";
// cin.getline(str3,12);
// cout<<str3<<endl;

//strings
string str4 = "sometimes you gotta run before you can walk";
cout<<str4.length()<<endl;

//string getline
string str5;
// getline(cin,str5,'%');
// cout<<str5<<endl;

//Reverse an string
char str6[] = "gulal";
int st = 0, e = strlen(str6)-1;

cout<<str6<<endl;
while(st<e){
    swap(str6[st],str6[e]);
    st++,e--;
}
cout<<str6<<endl;


return 0;
}