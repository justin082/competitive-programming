#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string s;
    std::cin >> s;

    for (int length = 1; length <= s.size() / 2; ++length) {
        if (s.size() % length != 0) continue;

        std::string ans = s.substr(0, length);
        std::string sort_ans = ans;
        sort(sort_ans.begin(), sort_ans.end());

        int start = length;
        bool correct = true;
        while (start + length <= s.size()) {
            std::string cur = s.substr(start, length);
            sort(cur.begin(), cur.end());
            
            if (cur != sort_ans) {
                correct = false;
                break;
            }
            start += length;
        }

        if (correct) {
            std::cout << ans << "\n";
            return 0;
        }
    }

    std::cout << -1 << "\n";
    return 0; 
}