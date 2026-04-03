#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index;
    Node* father;
};

Node* find(Node* cur) {
    if (cur->father != cur) cur->father = find(cur->father);
    return cur->father;
}

void join(std::vector<Node>& s, std::vector<int>& sz, std::vector<long long>& sum, int a, int b) {
    Node* f_a = find(&s[a]);
    Node* f_b = find(&s[b]);
    
    if (f_a == f_b) return;

    if (sz[f_a->index] < sz[f_b->index]) std::swap(f_a, f_b);
    sum[f_a->index] += sum[f_b->index];
    sz[f_a->index] += sz[f_b->index];
    f_b->father = f_a;
}

void move(std::vector<Node>& s, std::vector<int>& sz, std::vector<long long>& sum, int a, int b) {
    Node* f_a = find(&s[a]);
    Node* f_b = find(&s[b]);
    
    if (f_a == f_b) return;

    sz[f_a->index] -= 1;
    sum[f_a->index] -= a;
    sz[f_b->index] += 1;
    sum[f_b->index] += a;
    s[a].father = f_b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    while (std::cin >> n >> m) {
        std::vector<Node> f(n + 1);
        std::vector<Node> s(n + 1);
        std::vector<long long> sum(n + 1);
        std::vector<int> sz(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            f[i].father = &f[i];
            f[i].index = i;
            s[i].father = &f[i];
            s[i].index = i;
            sum[i] = i;
        }
        
        for (int i = 0; i < m; ++i) {
            int op, p, q;
            std::cin >> op;
            if (op == 1) {
                std::cin >> p >> q;
                join(s, sz, sum, p, q);
            }
            else if (op == 2) {
                std::cin >> p >> q;
                move(s, sz, sum, p, q);
            }
            else if (op == 3) {
                std::cin >> p;
                int f_p = find(&s[p])->index;
                std::cout << sz[f_p] << " " << sum[f_p] << "\n";
            }
        }
    }

    return 0; 
}