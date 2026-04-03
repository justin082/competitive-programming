#include <bits/stdc++.h>
using namespace std;

struct Node {
    int forced_move = -1;
    std::vector<int> moves;
};

int ans = 0;

void dfs(std::vector<Node>& nodes, std::vector<bool>& visited, int index, bool forced) {
    visited[index] = true;
    
    if (nodes[index].forced_move != -1 && !visited[nodes[index].forced_move]) {
        dfs(nodes, visited, nodes[index].forced_move, forced);
    }
    
    if (!forced) {
        if (nodes[index].forced_move == -1) ++ans;
        
        for (const auto& neighbor : nodes[index].moves) {
            if (!visited[neighbor])
                dfs(nodes, visited, neighbor, true);
        }
    }
    
    if (forced && nodes[index].forced_move == -1) ++ans;
    
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Node> nodes(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;

        if (a < 0) nodes[-a].forced_move = b;
        else nodes[a].moves.push_back(b);
    }

    std::vector<bool> visited(n + 1, false);
    dfs(nodes, visited, 1, false);
    
    std::cout << ans << "\n";
    return 0; 
}