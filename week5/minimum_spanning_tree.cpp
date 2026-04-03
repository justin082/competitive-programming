#include <bits/stdc++.h>
using namespace std;

int find(std::vector<int>& f, int index) {
    if (f[index] != index) f[index] = find(f, f[index]);
    return f[index];
}

bool join(std::vector<int>& f, std::vector<int>& sz, int x, int y) {
    int f_x = find(f, x);
    int f_y = find(f, y);
    if (f_x == f_y) return true;

    if (sz[f_x] < sz[f_y]) std::swap(f_x, f_y);
    sz[f_x] += sz[f_y];
    f[f_y] = f_x;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;

        std::vector<std::tuple<int, int, int>> weight(m); // weight, x, y
        for (int i = 0; i < m; ++i) {
            int x, y, w;
            std::cin >> x >> y >> w;
            weight[i] = std::make_tuple(w, std::min(x, y), std::max(x, y));
        }
        std::sort(weight.begin(), weight.end());

        std::vector<int> f(n);
        std::vector<int> sz(n, 1);
        for (int i = 0; i < n; ++i) f[i] = i;

        int counter = 0;
        long long sum = 0;
        std::vector<std::tuple<int, int>> ans(n - 1);
        for (const auto& we : weight) {
            int w = std::get<0>(we);
            int x = std::get<1>(we);
            int y = std::get<2>(we);

            if (join(f, sz, x, y)) continue;

            sum += w;
            ans[counter++] = std::make_tuple(x, y);
            if (counter == n - 1) break;
        }

        int r = find(f, 0);
        bool possible = true;
        for (int i = 1; i < n; ++i) {
            if (find(f, i) != r) {
                std::cout << "Impossible" << "\n";
                possible = false;
                break;
            }
        }

        std::sort(ans.begin(), ans.end());
        if (possible) {
            std::cout << sum << "\n";
            for (const auto& a : ans) {
                std::cout << std::get<0>(a) << " " << std::get<1>(a) << "\n";
            }
        }
    }

    return 0; 
}