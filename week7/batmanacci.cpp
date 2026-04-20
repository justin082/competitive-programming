#include <bits/stdc++.h>
using namespace std;

#define MAX 1e18

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;

    std::vector<unsigned long long> len(n + 1);
    len[1] = 1;
    len[2] = 1;
    for (long long i = 3; i <= n; ++i) {
        if (len[i - 1] > MAX - len[i - 2]) {
            len[i] = MAX;
        }
        else {
            len[i] = len[i - 2] + len[i - 1];
        }
    }

    while (n > 2) {
        if (k <= len[n - 2]) {
            n -= 2;
        }
        else {
            k -= len[n - 2];
            n -= 1;
        }
    }

    if (n == 1) std::cout << "N" << "\n";
    else std::cout << "A" << "\n";
    return 0; 
}