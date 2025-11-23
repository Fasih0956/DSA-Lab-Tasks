#include<iostream>
using namespace std;

bool isSafe(int maze[5][5], int x, int y, int sol[5][5]){
    return (x >= 0 && x < 5 && y >= 0 && y < 5 &&
            maze[x][y] == 1 && sol[x][y] == 0);
}
bool solveMaze(int maze[5][5], int x, int y, int sol[5][5]){
    if(x== 5 - 1 && y== 5 - 1){
        sol[x][y]= 1;
        return true;
    }
    if(isSafe(maze, x, y, sol)){
        sol[x][y]= 1;

        if (solveMaze(maze, x + 1, y, sol)) return true;
        if (solveMaze(maze, x, y + 1, sol)) return true;
        if (solveMaze(maze, x - 1, y, sol)) return true;
        if (solveMaze(maze, x, y - 1, sol)) return true;

        sol[x][y] = 0;
        return false;
    }
    return false;
}
void solveMaze(int maze[5][5]){
    int sol[5][5]= {0};

    if(!solveMaze(maze, 0, 0, sol)){
        cout << "No path found"<<endl;
        return;
    }
    cout<<"Solution path:"<<endl;
    for(int i= 0; i <5; i++){
        for(int j= 0; j< 5; j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int maze[5][5]={
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    solveMaze(maze);
    return 0;
}
