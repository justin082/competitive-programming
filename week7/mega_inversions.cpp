#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    std::vector<int> tree;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void update(int i, int v) {
        for (; i <= n; i += i & -i) {
            tree[i] += v;
        }
    }

    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::vector<int> comp = nums;
    std::sort(comp.begin(), comp.end());
    comp.erase(std::unique(comp.begin(), comp.end()), comp.end());

    auto get_id = [&](int x) {
        return std::lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
    };

    std::vector<long long> L(n), R(n);

    BIT bit_l(comp.size());
    for (int i = 0; i < n; ++i) {
        int id = get_id(nums[i]);
        L[i] = i - bit_l.query(id);
        bit_l.update(id, 1);
    }

    BIT bit_r(comp.size());
    for (int i = n - 1; i >= 0; --i) {
        int id = get_id(nums[i]);
        R[i] = bit_r.query(id - 1);
        bit_r.update(id, 1);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += L[i] * R[i];
    }

    std::cout << ans << "\n";
    return 0;
}