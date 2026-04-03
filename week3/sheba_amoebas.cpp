#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[105][105];
int pos_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int pos_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y) {
    grid[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
        int dx = x + pos_x[i];
        int dy = y + pos_y[i];

        if (dx >=0 && dx < rows && dy >= 0 && dy < cols && grid[dx][dy] == '#') {
            dfs(dx, dy);
        }
    }
}

int main() {
    std::cin >> rows >> cols;

    for (int i = 0; i < rows; ++i)
        std::cin >> grid[i];

    int loops = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '#') {
                dfs(i, j);
                ++loops;
            }
        }
    }

    std::cout << loops << std::endl;

    return 0;
}