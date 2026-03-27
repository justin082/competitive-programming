#include <bits/stdc++.h>
using namespace std;

int main() {
    double fact = 1.0;
    double sum = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i <= n; ++i) {
        if (i > 0) fact *= i;
        sum += 1.0 / fact;
    }

    std::cout << fixed << setprecision(15) << sum << "\n";
    return 0;
}