#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    int m;
    cin >> m;

    int max_order = 0;
    vector<int> orders(m);
    for (int i = 0; i < m; ++i) {
        cin >> orders[i];
        max_order = max(max_order, orders[i]);
    }

    vector<int> dp(max_order + 1, -1);  // -2 ambiguous, -1 impossible, >=0 last item
    dp[0] = -3;

    for (int i = 0; i < n; ++i) {
        for (int s = costs[i]; s <= max_order; ++s) {
            if (dp[s - costs[i]] == -1) continue;

            if (dp[s - costs[i]] == -2) dp[s] = -2;
            else if (dp[s] == -1) dp[s] = i;
            else dp[s] = -2;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (dp[orders[i]] == -2) cout << "Ambiguous" << "\n";
        else if (dp[orders[i]] == -1) cout << "Impossible" << "\n";
        else {
            int target = orders[i];
            vector<int> ans;

            while (target > 0) {
                ans.push_back(dp[target] + 1);
                target -= costs[dp[target]];
            }

            sort(ans.begin(), ans.end());
            for (const auto& idx : ans) {
                cout << idx << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}