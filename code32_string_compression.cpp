#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

int stringCompression(vector<char> &chars){
    int idx = 0;
    int n = chars.size();

    for(int i = 0; i<n;i++){
        char ch = chars[i];
        int count = 0;

        while(i<n && chars[i] == ch){
            count++;
            i++;
        }
        if(count == 1){
            chars[idx] = ch;
            idx++;
        }else{
            chars[idx] = ch;
            idx++;
            string str = to_string(count);

            for(char dig : str){
                chars[idx] = dig;
                idx++;
            }
        }
        i--;
    }
    chars.resize(idx);
    //printing
    for(char l:chars){
        cout<<l<<" ";
    }
    cout<<endl;
    return idx;
}
 
int main(){
system("cls");

vector<char> chars = {'a'};
cout<<stringCompression(chars);
 
return 0;
}