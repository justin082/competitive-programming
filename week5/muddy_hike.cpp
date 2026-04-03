#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    std::cin >> r >> c;

    std::vector<std::vector<int>> grid(r, std::vector<int>(c));
    std::vector<std::vector<int>> dist(r, std::vector<int>(c, INT_MAX));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::priority_queue<std::tuple<int, int, int>, 
                        std::vector<std::tuple<int, int, int>>, 
                        std::greater<std::tuple<int, int, int>>> pq;
    for (int i = 0; i < r; ++i) {
        dist[i][0] = grid[i][0];
        pq.emplace(grid[i][0], i, 0);
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!pq.empty()) {
        int cost = std::get<0>(pq.top());
        int x = std::get<1>(pq.top());
        int y = std::get<2>(pq.top());
        pq.pop();

        if (cost > dist[x][y]) continue;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            int new_cost = std::max(cost, grid[nx][ny]);
            if (new_cost < dist[nx][ny]) {
                dist[nx][ny] = new_cost;
                pq.emplace(new_cost, nx, ny);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < r; ++i) {
        ans = std::min(ans, dist[i][c - 1]);
    }

    std::cout << ans << "\n";
    return 0; 
}