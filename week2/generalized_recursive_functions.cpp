#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    static const int BASE = 1e9;
    std::vector<int> d; // little endian

    // constructor
    BigInt(long long x = 0) {
        if (x == 0) d = {0};
        while (x) {
            d.push_back(x % BASE);
            x /= BASE;
        }
    }

    BigInt operator+(const BigInt& o) const {
        BigInt res;
        res.d.clear();
        long long carry = 0;

        for (size_t i = 0; i < std::max(d.size(), o.d.size()) || carry; ++i) {
            long long sum = carry;
            if (i < d.size()) sum += d[i];
            if (i < o.d.size()) sum += o.d[i];

            res.d.push_back(sum % BASE);
            carry = sum / BASE;
        }
        return res;
    }

    BigInt& operator+=(const BigInt& o) {
        *this = *this + o;
        return *this;
    }

    std::string str() const {
        std::stringstream ss;
        ss << d.back();
        for (int i = (int)d.size() - 2; i >= 0; --i) {
            ss << setw(9) << setfill('0') << d[i];
        }
        return ss.str();
    }
};

int a[20];
int b[20];
int c, d;
BigInt dp[100][100];
bool vis[100][100];

BigInt solve(const int& n, const int& x, const int& y) {
    if (x <= 0 || y <= 0) return BigInt(d);
    if (vis[x][y]) return dp[x][y];

    vis[x][y] = true;

    BigInt ans(c);
    for (int i = 0; i < n; ++i) {
        ans += solve(n, x - a[i], y - b[i]);
    }
    return dp[x][y] = ans;
}

int main() {
    int cases;
    std::cin >> cases;
    std::cin.ignore();

    while (cases--) {
        std::string s;
        std::getline(std::cin, s);
        std::stringstream s1;
        s1 << s;

        int n = 0;
        while (s1 >> a[n] >> b[n]) {
            ++n;
        }
        n -= 1;
        c = a[n];
        d = b[n];
        
        memset(vis, 0, sizeof(vis));

        std::getline(std::cin, s);
        std::stringstream s2;
        s2 << s;
        
        int x, y;
        while (s2 >> x >> y) {
            std::cout << solve(n, x, y).str() << "\n";
        }
        std::cout << "\n";
        
    }

    return 0;
}