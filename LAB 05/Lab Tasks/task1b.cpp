#include <iostream>
using namespace std;

bool isSafe(int maze[4][4], int sol[4][4], int x, int y) {
    return (x >= 0 && x < 4 && y >= 0 && y < 4 && maze[x][y] == 1 && sol[x][y] == 0);
}
bool backtrack(int maze[4][4], int sol[4][4], int x, int y, int tx, int ty) {
    if (!isSafe(maze, sol, x, y)) return false;
    sol[x][y] = 1;
    if (x == tx && y == ty) return true;
    if (backtrack(maze, sol, x, y + 1, tx, ty)) return true;
    if (backtrack(maze, sol, x + 1, y, tx, ty)) return true;
    if (backtrack(maze, sol, x, y - 1, tx, ty)) return true;
    if (backtrack(maze, sol, x - 1, y, tx, ty)) return true;
    sol[x][y] = 0;
    return false;
}
int main() {
    const int n = 4;
    int maze[n][n] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };
    int sol[n][n] = {0};

    if (backtrack(maze, sol, 2, 0, 0, 0)) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path exists\n";
    }
}