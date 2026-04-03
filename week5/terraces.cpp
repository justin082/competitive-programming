#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(m, std::vector<int>(n)); 
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    } 

    int ans = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j]) continue;

            std::queue<std::pair<int, int>> q;
            std::vector<std::pair<int, int>> comp;

            q.push({i, j});
            visited[i][j] = true;

            int height = grid[i][j];
            bool can_flow = false;

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                comp.push_back({x, y});
                
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (grid[nx][ny] < height) 
                        can_flow = true;
                    
                    if (!visited[nx][ny] && grid[nx][ny] == height) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            if (!can_flow) {
                ans += comp.size();
            }
        }
    }

    std::cout << ans << "\n";
    return 0; 
}