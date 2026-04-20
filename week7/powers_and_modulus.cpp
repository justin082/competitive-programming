#include <bits/stdc++.h>
using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    std::cin >> a >> b;

    std::cout << (a % 2 == 0 ? modPow(a / 2, b, a) : 0) << "\n";
    return 0; 
}