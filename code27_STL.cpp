#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

//Custom comparator bool function
bool myComparator(pair<int, int> p1, pair<int, int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    //if are equal
    if(p1.first < p2.first) return true;
    else return false;
}

 

 
int main(){
system("cls");

vector<int> vec;

vec.push_back(1);
vec.push_back(3);
vec.push_back(3);
vec.push_back(4);

// for(int v: vec){
//     cout<<v<<endl;
// }


//Map

map<string,int> m;

m["tv"] = 20;
m["laptop"] = 50;
m["fridge"] = 2;

m["headphones"] = 60;

m.insert({"watch",100});

//printing
for(auto val: m){
    cout<<val.first<<" "<<val.second<<endl;
}
//Gets sorted lexicographically itself
cout<<m.count("laptop")<<endl;
if(m.find("fridge") !=m.end()){
    cout<<"Found";
}else{
    cout<<"NOT Found";
}
cout<<endl;














//Set 
set<int> s;
s.insert(1);
s.insert(2);
s.emplace(3);
s.insert(4);
s.insert(5);

//printing
cout<<"set : ";
for(auto val: s){
    cout<<val<<" ";
}
cout<<endl;

cout<<"Lower bound "<<*(s.lower_bound(3))<<" "<<endl;
cout<<"Upper bound "<<*(s.upper_bound(4))<<" "<<endl;

//Sorting Algorithms

int arr[5] = {1,4,2,3,5};

cout<<"sorted : ";

sort(arr,arr + 5);
for(auto a: arr){
    cout<<a<<" ";
}
cout<<endl;

//for decending
sort(arr,arr+5,greater<int>());

cout<<"Descending sorted : ";

for(auto a: arr){
    cout<<a<<" ";
}
cout<<endl;



//Custom comparators

vector<pair<int,int>> vec2 = {{3,1},{2,1},{7,1},{5,2}};
sort(vec2.begin(),vec2.end(),myComparator);

//printing

cout<<"sorted by custom comparator : "<<endl;
for(auto val: vec2){
    cout<<val.first<<" "<<val.second<<endl;
}
cout<<endl;





//Binary search
vector<int> vec1 = {1,2,3,4,5};
cout<<binary_search(vec1.begin(),vec1.end(),3)<<endl;



//Count Set Bits
int n = 15;
cout<<"Built in count "<<__builtin_popcount(n)<<endl;



return 0;
}