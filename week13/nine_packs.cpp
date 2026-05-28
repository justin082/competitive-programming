#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h;
    cin >> h;

    int total_hotdogs = 0;
    vector<int> hotdogs(h);
    for (int i = 0; i < h; ++i) {
        cin >> hotdogs[i];
        total_hotdogs += hotdogs[i];
    }

    int b;
    cin >> b;
    
    int total_buns = 0;
    vector<int> buns(b);
    for (int i = 0; i < b; ++i) {
        cin >> buns[i];
        total_buns += buns[i];
    }

    int m = min(total_hotdogs, total_buns);

    vector<int> dp_h(m + 1, MAX);
    dp_h[0] = 0;
    for (const auto& hotdog : hotdogs) {
        for (int j = m; j >= hotdog; --j) {
            dp_h[j] = min(dp_h[j], dp_h[j - hotdog] + 1);
        }
    }

    vector<int> dp_b(m + 1, MAX);
    dp_b[0] = 0;
    for (const auto& bun : buns) {
        for (int j = m; j >= bun; --j) {
            dp_b[j] = min(dp_b[j], dp_b[j - bun] + 1);
        }
    }

    int ans = MAX;
    for (int i = 1; i <= m; ++i) {
        if (dp_h[i] != MAX && dp_b[i] != MAX) {
            ans = min(ans, dp_h[i] + dp_b[i]);
        }
    }

    if (ans != MAX) cout << ans << "\n";
    else cout << "impossible" << "\n";
    return 0;
}