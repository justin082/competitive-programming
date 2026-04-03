#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;

    std::vector<int> crank(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> crank[i];
    }

    std::vector<int> back_wheel(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> back_wheel[i];
    }

    std::vector<double> gear_ratios;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            gear_ratios.push_back(static_cast<double>(crank[i]) / back_wheel[j]);
        }
    }

    std::sort(gear_ratios.begin(), gear_ratios.end());

    for (int i = 1; i < gear_ratios.size(); ++i) {
        if (gear_ratios[i] / gear_ratios[i - 1] > 1 + p / 100.0) {
            std::cout << "Time to change gears!" << std::endl;
            return 0;
        }
    }
    std::cout << "Ride on!" << std::endl;

    return 0;
}