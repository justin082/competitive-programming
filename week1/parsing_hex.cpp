#include <bits/stdc++.h>
using namespace std;

int main() {
    std::string line;
    std::vector<std::string> hex;
    while (std::getline(std::cin, line)) {
        for (int i = 0; i < line.size(); ++i) {
            if (i + 2 < line.size() && line[i] == '0' && (line[i + 1] == 'x' || line[i + 1] == 'X')) {
                std::string s = "0";
                s += line[i + 1];
                i += 2;
                int count = 0;

                while (i < line.size() && count < 8 &&
                       ((line[i] >= '0' && line[i] <= '9') ||
                       (line[i] >= 'a' && line[i] <= 'f') ||
                       (line[i] >= 'A' && line[i] <= 'F'))) {
                    s += line[i];
                    ++i;
                    ++count;
                }

                hex.push_back(s);
            }
        }
    }

    for (const auto& s : hex) {
        std::cout << s << " " << std::stoll(s, nullptr, 16) << std::endl;
    }

    return 0;
}