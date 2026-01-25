#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();

    int stRow = 0,eRow = m-1 ,stCol = 0,eCol = n-1;

    vector<int> ans;

    while(stRow <= eRow && stCol <= eCol){
        //top
        for(int j = stCol;j<=eCol;j++){
            ans.push_back(mat[stRow][j]);
        }

        //right
        for(int i = stRow+1;i <= eRow;i++){
            ans.push_back(mat[i][eCol]);
        }

        //bottom
        for(int j = eCol-1;j>=stCol;j--){
            if(stRow == eRow){
                break;
            }
            ans.push_back(mat[eRow][j]);
        }

        //left
        for(int i = eRow-1;i >= stRow+1;i--){
            if(stCol == eCol){
                break;
            }
            ans.push_back(mat[i][stCol]);
        }

        stRow++,eRow--,stCol++,eCol--;
    }
    return ans;

}
 
int main(){
system("cls");
vector<vector<int>> mat = {
    {1,  2,  3,  4},
    {5,  6,  7,  8},
    {9, 10, 11, 12}
};


vector<int> ansGiven = spiralOrder(mat);

//printing
for(int l:ansGiven){
    cout<<l<<" ";
}
 
return 0;
}