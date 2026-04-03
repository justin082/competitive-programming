#include <bits/stdc++.h>
using namespace std;

int main() {
    int people, close_time;
    std::cin >> people >> close_time;
    std::vector<std::vector<int>> person(close_time + 1); 

    while (people--) {
        int cash, time;
        std::cin >> cash >> time;
        if (time <= close_time) {
            person[time].push_back(cash);
        }
    }

    std::priority_queue<int> pq;
    long long total_cash = 0;

    for (int t = close_time; t >= 0; --t) {
        for (int cash : person[t]) {
            pq.push(cash);
        }

        if (!pq.empty()) {
            total_cash += pq.top();
            pq.pop();
        }
    }

    std::cout << total_cash << std::endl;
    
    return 0;
}