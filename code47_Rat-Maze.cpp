#include<iostream>
#include<cstdlib>
#include<vector>
 
using namespace std;


void helper(vector<vector<int>> &maze, int r, int c, string path, vector<string> &ans){

    int n = maze.size();

    if( r<0 || c<0 || r>=n || c>=n || maze[r][c] == 0 || maze[r][c] == -1){
        return;
    }

    //base case
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    maze[r][c] = -1;

    //calling helpers
    helper(maze,r+1,c,path+'D',ans);    //down
    helper(maze,r-1,c,path+'U',ans);    //up
    helper(maze,r,c+1,path+'R',ans);    //right
    helper(maze,r,c-1,path+'L',ans);    //left

    maze[r][c] = 1;

}

vector<string> mazePath(vector<vector<int>> &maze){
    int n = maze.size();
    vector<string> ans;
    string path = "";

    helper(maze,0,0,path,ans);

    return ans;
}


int main(){
    system("cls");
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    

    vector<string> ans = mazePath(maze);

    for(string v:ans){
        cout<<v<<endl;
    }
    return 0;
}