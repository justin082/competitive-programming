#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::vector<bool> can_be_entered(201, false);
    for (int i = 1; i <= 9; ++i) {
        can_be_entered[i] = true;
        int one_remainder = (i - 1) % 3;

        if (i % 3 != 0) can_be_entered[i * 10] = true;
        if (i <= 2) can_be_entered[i * 100] = true;
        for (int j = i; j <= 9; ++j) {
            if (j != 0 && (j - 1) % 3 < one_remainder) continue;

            int two_digits = i * 10 + j;
            can_be_entered[two_digits] = true;
            int two_remainder = (j - 1) % 3;

            if (i == 1 && j % 3 != 0) can_be_entered[i * 100 + j * 10] = true;
            for (int k = j; i == 1 && k <= 9; ++k) {
                if (k != 0 && (k - 1) % 3 < two_remainder) continue;
                
                int three_digits = i * 100 + j * 10 + k;
                can_be_entered[three_digits] = true;
            }
        }
    }

    int n;
    std::cin >> n;
    while (n--) {
        int cur;
        std::cin >> cur;

        if (can_be_entered[cur]) {
            std::cout << cur << "\n";
            continue;;
        }
        
        int diff = 1;
        while (1) {
            if (cur + diff <= 200 && can_be_entered[cur + diff]) {
                std::cout << cur + diff << "\n";
                break;
            }
            else if (cur - diff > 0 && can_be_entered[cur - diff]) {
                std::cout << cur - diff << "\n";
                break;
            }

            ++diff;
            if (cur + diff > 200 && cur - diff <= 0) break;
        }
    }
    return 0; 
}