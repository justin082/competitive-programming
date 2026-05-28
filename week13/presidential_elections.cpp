#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 

    vector<pair<int, int>> states;
    ll total = 0;
    ll guarantee = 0;
    for (int i = 0; i < n; ++i) {
        int d, c, f, u;
        cin >> d >> c >> f >> u;

        if (c > f + u) {
            guarantee += d;
        }
        else if (c + u > f) {
            int cost = (f + u - c) / 2 + 1;
            states.push_back({d, cost});
        }

        total += d;
    }

    const ll target = (total / 2) + 1;
    if (guarantee >= target) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> dp(total + 1, INF);
    dp[0] = 0;

    for (const auto& [d, cost] : states) {
        for (ll j = total; j >= d; --j) {
            dp[j] = min(dp[j], dp[j - d] + cost);
        }
    }

    ll ans = INF;
    ll need = target - guarantee;
    for (ll i = need; i <= total; ++i) {
        ans = min(ans, dp[i]);
    }

    if (ans == INF) cout << "impossible" << "\n";
    else cout << ans << "\n";

    return 0;
}