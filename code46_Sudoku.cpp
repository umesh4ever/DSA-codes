#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;

//printing
void printBoard(vector<vector<char>> &board){
    for(int i = 0; i < 9; i++){

        if(i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";

        for(int j = 0; j < 9; j++){

            if(j % 3 == 0 && j != 0)
                cout << "| ";

            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

bool isSafe(vector<vector<char>> &board,int row,int col,char dig){
    //horizontal 
    for(int j = 0;j<9;j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //vertical 
    for(int i = 0;i<9;i++){
        if(board[i][col] == dig){
            return false;
        }
    }
    //grid check
    int sRow = (row/3)*3;
    int sCol = (col/3)*3;

    for(int i = sRow;i<=sRow+2;i++){
        for(int j = sCol;j<=sCol+2;j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<char>> &board,int row, int col){

    //base case
    if(row == 9){
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == 9){
        nextRow = row+1;
        nextCol = 0;
    }



    if(board[row][col] != '.'){
        return sudoku(board,nextRow,nextCol);
    }else{
        
        for(char dig = '1';dig <= '9';dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;

                //if we get  an true return after calling
                if(sudoku(board,nextRow,nextCol)){
                    return true;
                }
                //backtracking
                board[row][col] = '.';
            }
        }
    }

    return false;

}
 
int main(){
system("cls");



vector<vector<char>> board = {
{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}
};

sudoku(board,0,0);


//printing

printBoard(board);
 
return 0;
}