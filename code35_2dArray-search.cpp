#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

bool searchInRow(vector<vector<int>> &mat,int target, int midRow){      //O(logn)
    int n = mat[0].size();

    int st = 0;
    int end = n-1;

    while(st<=end){
        int mid = st + (end-st)/2;

        if(target == mat[midRow][mid]){
            return true;
        }else if(target > mat[midRow][mid]){
            st = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return false;
}
 
bool searchInMatrixI(vector<vector<int>> &mat,int target){      //O(logm)
    int m = mat.size();
    int n = mat[0].size();
    
    int stRow = 0;
    int endRow = m-1;

    while(stRow <= endRow){
        int midRow = stRow + (endRow-stRow)/2;

        if(target >= mat[midRow][0] && target <= mat[midRow][n-1]){
            return searchInRow(mat,target,midRow);
        }else if(target <= mat[midRow][0]){
            endRow = midRow - 1;
        }else{
            stRow = midRow + 1;
        }
    }
    return false;
}

bool searchInMatrixII(vector<vector<int>> &mat,int target){     //O(m+n)
    int m = mat.size();
    int n = mat[0].size();

    int r = 0;
    int c = n-1;

    while(r <= m-1 && c >= 0){      //runs for (m+n) times
        if(target == mat[r][c]){
            return true;
        }else if(target < mat[r][c]){       //curr value tar se badi hai
            c-- ;
        }else if(target > mat[r][c]){       //curr value tar se choti hai
            r++ ;
        }
    }
    return false;
}

int main(){
system("cls");

//calling search in 2D array I
vector<vector<int>> matrix1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
int target1 = 34;
cout<<searchInMatrixI(matrix1,target1)<<endl;     //Total time complexity sums upto O(logm + logn ==> log(m*n)))

//calling search in 2D array II

vector<vector<int>> matrix2 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
int target2 = 5;

cout<<searchInMatrixII(matrix2,target2)<<endl;     //Total time complexity sums upto O(logm + logn ==> log(m*n)))
 
return 0;
}