#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int cur = 0, m;
        for (int j = 0; j < n; ++j) {
            std::cin >> m;
            if (j != i) cur |= m;
        }
        
        std::cout << cur << " ";
    }
    
    return 0;
}