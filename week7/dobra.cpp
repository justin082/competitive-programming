#include <bits/stdc++.h>
using namespace std;

bool LExist(std::string& s) {
    for (const auto& c : s) {
        if (c == 'L') return true;
    }
    return false;
}

bool isVowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
    return false;
}

void findPleasantWords(long long& ans, long long ways, int cur_vowels, int cur_consonants, bool l_exist, int index, std::string s) {
    if (cur_vowels >= 3 || cur_consonants >= 3) return;
    if (index == s.size() && l_exist) {
        ans += ways;
        return;
    }

    if (s[index] == '_') {
        // vowel
        findPleasantWords(ans, ways * 5, cur_vowels + 1, 0, l_exist, index + 1, s);
        // consonant
        findPleasantWords(ans, ways * 20, 0, cur_consonants + 1, l_exist, index + 1, s);
        // l
        findPleasantWords(ans, ways, 0, cur_consonants + 1, true, index + 1, s);
    }
    else {
        if (isVowel(s[index])) findPleasantWords(ans, ways, cur_vowels + 1, 0, l_exist, index + 1, s);
        else findPleasantWords(ans, ways, 0, cur_consonants + 1, l_exist, index + 1, s);
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    long long ans = 0;
    findPleasantWords(ans, 1, 0, 0, LExist(s), 0, s);

    std::cout << ans << "\n";
    return 0; 
}