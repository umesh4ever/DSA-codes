#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

//Linear search in a 2D array
bool linearSearch(int mat[][3],int rows,int cols, int key,pair<int,int> &p){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if( mat[i][j] == key){
                p.first = i,p.second = j;
                return true;
            }
        }
    }
    p.first = -1,p.second = -1;
    return false;
}

//Max Row Sum 
int maxRowSum(int mat[][3],int rows,int cols){
    int maxSum = INT16_MIN;

    for(int i=0;i<rows;i++){
        int rowSumI=0;

        for(int j=0;j<cols;j++){
           rowSumI += mat[i][j];
        }
        maxSum = max(maxSum,rowSumI);
    }
    return maxSum;
}

//Diagonal Sum in a 2D array
int diagonalSum(int mat[][4],int n){
    int diagSum = 0;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
           if(i == j){
            diagSum += mat[i][j];
           }else if(j == n-i-1){
            diagSum += mat[i][j]; 
           }
        }
    }
    return diagSum;
}
//Diagonal Sum in a 2D array BUT BETTER
int diagonalSumBETTER(int mat[][3],int n){
    int diagSum = 0;

    for(int i=0;i<n;i++){
        diagSum += mat[i][i];
        if(i != n-i-1){
            diagSum += mat[i][n-i-1];
        }
    }
    return diagSum;
}
 
int main(){
system("cls");

int matrix1[4][4] = {{1,2,3,4},{4,5,6,7},{7,8,9,10},{10,11,12,13}};
int matrix2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

int rows = 4;
int cols = 3;

//input
// cout<<"Enter matrix element values: ";
// for(int i=0;i<rows;i++){
//     for(int j=0;j<cols;j++){
//         cin>>matrix[i][j];
//     }
// }

//output for 4-4 matrix
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        cout<<matrix1[i][j]<<" ";
    }
    cout<<endl;
}

pair<int,int> p;
cout<<"It exists or NOT: "<<linearSearch(matrix2, rows,cols,88,p)<<endl;
cout<<"Matrix pair: "<<"("<<p.first<<","<<p.second<<")"<<endl;

cout<<"Max row sum is: "<<maxRowSum(matrix2, rows,cols)<<endl;
cout<<"Diagonal sum is: "<<diagonalSumBETTER(matrix2, 4)<<endl;

//2D Vectors

vector<vector<int>> mat = {{1,2,3},{4,5,8,7,6},{7,8,9},{5},{6}} ;

cout<<"No. of rows in the vec mat: "<<mat.size()<<endl;
cout<<"No. of cols in a particular row vec mat: "<<mat[1].size()<<endl;

//output for 4-4 matrix
for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[i].size();j++){
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
}


return 0;
}