#include <bits/stdc++.h>
using namespace std;

struct Node {
    std::vector<int> connects;
    bool internet = false;
};

void bfs(std::vector<Node*>& nodes) {
    std::queue<Node*> q;
    q.push(nodes[1]);
    q.front()->internet = true;

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        for (const auto& neighbor : cur->connects) {
            if (nodes[neighbor]->internet) continue;

            nodes[neighbor]->internet = true;
            q.push(nodes[neighbor]);
        }
    }
}

int main() {
    int n, p;
    std::cin >> n >> p;

    std::vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new Node();
    }
    
    while (p--) {
        int a, b;
        std::cin >> a >> b;

        nodes[a]->connects.push_back(b);
        nodes[b]->connects.push_back(a);
    }

    bfs(nodes);
    
    std::vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (!nodes[i]->internet) result.push_back(i);
    }

    if (result.size() == 0) std::cout << "Connected" << "\n";
    else {
        sort(result.begin(), result.end());
        for (const auto& h : result) std::cout << h << "\n";
    }
    return 0; 
}