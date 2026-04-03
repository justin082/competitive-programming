#include <bits/stdc++.h>
using namespace std;

void minusOne(std::string& s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';
        --i;
    }
    if (i >= 0) --s[i];
    
    // delete leading zeros
    int pos = 0;
    while (pos + 1 < s.size() && s[pos] == '0') {
        ++pos;
    }
    if (pos) s.erase(0, pos);
}

void devideByTwo(std::string& s) {
    int carry = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        int cur = carry * 10 + (s[i] - '0');
        s[i] = (cur / 2) + '0';
        carry = cur % 2;
    }
    
    // delete leading zeros
    int pos = 0;
    while (pos + 1 < s.size() && s[pos] == '0') {
        ++pos;
    }
    s.erase(0, pos);
}

int main() {
    std::string num;
    long long k;
    std::cin >> num >> k;

    minusOne(num);

    int bits = 0;
    while (num != "0") {
        devideByTwo(num);
        ++bits;
    }
    
    if (k >= bits) std::cout << "Your wish is granted!" << std::endl;
    else std::cout << "You will become a flying monkey!" << std::endl;

    return 0;
}