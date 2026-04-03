#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    std::cin >> n;
    
    long long l = -1, r, low = INT64_MAX;
    long long max_distance = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> r;
        low = std::min(low, r);
        
        if (r > l) {
            max_distance = std::max(max_distance, l - low);
            low = INT64_MAX;
            l = r;
        }
        else {
            max_distance = std::max(max_distance, r - low);
        }
    }

    std::cout << max_distance << "\n";
    return 0;
}