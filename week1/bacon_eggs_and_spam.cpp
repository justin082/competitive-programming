#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::cin.ignore();
        std::map<std::string, std::vector<std::string>> m; // <order, names>
        
        while (n--) {
            std::string s;
            std::getline(std::cin, s);

            std::stringstream ss; 
            ss << s;
            std::string name;
            ss >> name;
            
            std::string order;
            while (ss >> order) {
                m[order].push_back(name);
            }
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            std::sort((*it).second.begin(), (*it).second.end());
            std::cout << (*it).first << " ";

            for (const auto& name : (*it).second) {
                std::cout << name << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}