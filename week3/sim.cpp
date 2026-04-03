#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    std::cin >> cases;
    std::cin.ignore();

    while (cases--) {
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);

        std::list<char> lst;
        char c;
        std::list<char>::iterator it = lst.begin();
        while (ss.get(c)) {
            if (c == '<') {
                if (it != lst.begin()) {
                    it = lst.erase(--it);
                }
            }
            else if (c == '[') {
                it = lst.begin();
            }
            else if (c == ']') {
                it = lst.end();
            }
            else {
                it = lst.insert(it, c);
                ++it;
            }
        }

        for (char c : lst) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    return 0;
}