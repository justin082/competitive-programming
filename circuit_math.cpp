#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> truth_value(n);
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        truth_value[i] = (c == 'T') ? 1 : 0;
    }

    std::stack<bool> st;
    char c;
    while (std::cin >> c) {
        if (c == '*') {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a && b);
        }
        else if (c == '+') {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(a || b);
        }
        else if (c == '-') {
            int a = st.top(); st.pop();
            st.push(!a);
        }
        else {
            st.push(truth_value[c - 'A']);
        }
    }

    if (st.top()) std::cout << 'T' << std::endl;
    else std::cout << 'F' << std::endl;

    return 0;
}