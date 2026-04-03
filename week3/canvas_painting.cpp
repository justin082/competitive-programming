#include <bits/stdc++.h>
using namespace std;

long long huffmanCode(int n, std::vector<long long> sizes) {
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq(sizes.begin(), sizes.end());
    long long cost = 0;

    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();

        cost += a + b;
        pq.push(a + b);
    }

    return cost;
}

int main() {
    int cases;
    std::cin >> cases;

    while (cases--) {
        int canvasses;
        std::cin >> canvasses;
        
        std::vector<long long> sizes(canvasses);
        for (long long i = 0; i < canvasses; i++) {
            std::cin >> sizes[i];
        }

        long long cost = huffmanCode(canvasses, sizes);
        std::cout << cost << std::endl;
    }

    return 0;
}