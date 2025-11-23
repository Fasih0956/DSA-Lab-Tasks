#include<iostream>
using namespace std;
int maxFlags= 0;
int grid[4][4];

bool isSafe(int board[4][4], int row, int col){
    for(int i= 0; i< row; i++){
        if(board[i][col]== 1) return false;
    }
    for(int i= row, j= col; i>= 0 && j >= 0; i--, j--){
        if (board[i][j] == 1) return false;
    }
    for(int i= row, j= col; i>= 0 && j< 4; i--, j++){
        if(board[i][j]== 1) return false;
    }
    return true;
}
void solve(int board[4][4], int row, int flagsPlaced){
    if(row== 4){
        if(flagsPlaced> maxFlags){
            maxFlags= flagsPlaced;
            for(int i= 0; i< 4; i++){
                for(int j= 0; j< 4; j++){
                    grid[i][j]= board[i][j];
                }
            }
        }
        return;
    }
    for(int col= 0; col< 4; col++){
        if(isSafe(board, row, col)){
            board[row][col]= 1;
            solve(board, row+ 1, flagsPlaced+ 1);
            board[row][col]=0;
        }
    }
    //solve(board, row +1, flagsPlaced);
}
int main(){
    int board[4][4]= {0};
    solve(board, 0, 0);
    
    cout<<"Maximum number of flags that can be placed is: "<< maxFlags<<endl;
    
    for(int i= 0; i< 4; i++){
        for(int j= 0; j< 4; j++){
            cout<<grid[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}