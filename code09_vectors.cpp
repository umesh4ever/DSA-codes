#include<iostream>
#include<cstdlib>

#include<vector>
using namespace std;
 
//SINGLE NUMBER
int singleNumber(vector<int>nums){
    int ans =0;

    for(int val: nums){
        ans=ans^val;
    }
    return ans;
}

int main(){
system("cls");

vector<int> vec1(4,2);
cout<<vec1[0]<<endl;
cout<<vec1[1]<<endl;
cout<<vec1[2]<<endl;
cout<<vec1[3]<<endl;


//For Each loop in vectors
vector<char> vec2 = {'u', 'm','e','s','h'};

for(char val: vec2){
    cout<<val;
}

//Vector Functions
cout<<endl<< "size: "<<vec2.size();
vec2.push_back('yo');       //adds to the end of the vector
vec2.pop_back();            //remove to the end of the vector
cout<<vec2.front()<<endl;   //gives the first value of the vector
cout<<vec2.back()<<endl;    //gives the last value of the vector
cout<<vec2.at(3)<<endl;     //gives the value at index 3 of the vector


//static vs dynamic memory allocation
vector<int> vec3;
vec3.push_back(0);
vec3.push_back(1);
vec3.push_back(3);
vec3.push_back(4);
vec3.push_back(5);
//after each push the size incr by the elements added
// and capacity doubles if the vector is full while pushing 
cout<<"size: "<<vec3.size()<<endl;
cout<<"capacity: "<<vec3.capacity()<<endl;

cout<<"Single number runnig here"<<endl;
vector<int>nums = {2,1,9,2,1};
cout<< singleNumber(nums);

return 0;

}