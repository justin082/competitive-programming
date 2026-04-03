#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1)); 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cin >> dist[i][j];
        }
    }
    
    std::vector<int> min_dist(n + 1, INT_MAX);
    std::vector<bool> used(n + 1, false);
    std::vector<int> parent(n + 1, -1);

    min_dist[1] = 0;
    for (int counter = 0; counter < n; ++counter) {
        int cur = -1;
        for (int i = 1; i <= n; ++i) {
            if (!used[i] && (cur == -1 || min_dist[i] < min_dist[cur])) {
                cur = i;
            }
        }
        used[cur] = true;

        if (parent[cur] != -1) std::cout << parent[cur] << " " << cur << "\n";

        for (int i = 1; i <= n; ++i) {
            if (!used[i] && dist[cur][i] < min_dist[i]) {
                min_dist[i] = dist[cur][i];
                parent[i] = cur;
            }
        }
    }

    return 0; 
}