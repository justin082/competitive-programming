#include <bits/stdc++.h>
using namespace std;

void countDigits(std::vector<int>& digits, long long target) {
    while (target > 0) {
        ++digits[target % 10];
        target /= 10;
    }
}

bool digitsCmp(std::vector<int>& a, std::vector<int>& b) {
    for (int i = 0; i < 10; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    std::vector<std::tuple<long long, long long, long long>> result;
    long long a, b;
    std::cin >> a >> b;
    
    for (long long i = a; i <= b; ++i) {
        for (long long j = i; j <= b; ++j) {
            if (i * j > b) break;

            std::vector<int> single(10, 0);
            std::vector<int> product(10, 0);

            countDigits(single, i);
            countDigits(single, j);
            countDigits(product, i * j);

            if (digitsCmp(single, product)) {
                result.push_back(std::make_tuple(i, j, i * j));
            }
        }
    }

    std::cout << result.size() << " digit-preserving pair(s)" << "\n";
    for (const auto pair : result) {
        std::cout << "x = " << std::get<0>(pair) 
                  << ", y = " << std::get<1>(pair) 
                  << ", xy = " << std::get<2>(pair) << "\n";
    }
    
    return 0;
}