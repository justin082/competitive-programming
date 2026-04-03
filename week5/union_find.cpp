#include <bits/stdc++.h>
using namespace std;

int find(std::vector<int>& root, int target) {
    if (root[target] != target) 
        root[target] = find(root, root[target]);
    return root[target];
}

void join(std::vector<int>& root, std::vector<int>& sz, int a, int b) {
    int a_root = find(root, a);
    int b_root = find(root, b);

    if (a_root == b_root) return;

    if (sz[a_root] < sz[b_root]) std::swap(a_root, b_root);
    sz[a_root] += sz[b_root];
    root[b_root] = a_root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> root(n);
    for (int i = 0; i < n; ++i) {
        root[i] = i;
    }

    char query;
    int a, b;
    std::vector<int> sz(n, 1);
    for (int i = 0; i < q; ++i) {
        std::cin >> query >> a >> b;

        if (query == '?') {
            if (find(root, a) == find(root, b)) std::cout << "yes" << "\n";
            else std::cout << "no" << "\n";
        }
        else {
            join(root, sz, a, b);
        }
    }

    return 0; 
}