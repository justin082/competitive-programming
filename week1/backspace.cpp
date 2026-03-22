#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> letters;

    for (const auto& c : s) {
        if (c != '<') {
            letters.push(c);
        }
        else if (!letters.empty()) {
            letters.pop();
        }
    }

    std::string result = "";
    while (!letters.empty()) {
        result.push_back(letters.top());
        letters.pop();
    }

    std::reverse(result.begin(), result.end());
    std::cout << result << std::endl;

    return 0;
}