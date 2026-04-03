#include <bits/stdc++.h>
using namespace std;

bool is_open(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool is_match(char c, char match) {
    return ((c == ')' && match == '(') || 
            (c == ']' && match == '[') || 
            (c == '}' && match == '{'));
}

int main() {
    int size;
    std::cin >> size;
    std::cin.ignore();

    std::stack<char> st;
    std::string s;
    std::getline(std::cin, s);
    
    for (int i = 0; i < size; ++i) {
        char c = s[i];

        if (c == ' ') continue;

        if (is_open(c)) {
            st.push(c);
        }
        else {
            if (st.empty() || !is_match(c, st.top())) {
                std::cout << c << " " << i << std::endl;
                return 0;
            }
            st.pop();
        }
    }

    std::cout << "ok so far" << std::endl;

    return 0;
}