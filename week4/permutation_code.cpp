#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    while (std::cin >> x) {
        if (x == 0) break;
        
        std::string s, p, c;
        std::cin >> s >> p >> c;

        int n = c.size();
        std::unordered_map<char, int> posS;
        std::unordered_map<char, int> posP;

        for (int i = 0; i < s.size(); ++i) {
            posP[p[i]] = i;
            posS[s[i]] = i;
        }

        int d = ((int) std::pow(n, 1.5) + x) % n;
        
        std::string m = c;
        m[d] = p[posS[c[d]]];
        for (int i = 0, index = (d - 1 + n) % n; i < n - 1; ++i) {
            m[index] = p[posS[c[index]] ^ posS[m[(index + 1) % n]]];
            index = (index - 1 + n) % n;
        }
        std::cout << m << "\n";
    }

    return 0; 
}