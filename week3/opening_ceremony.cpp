#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums;
    std::cin >> nums;
    std::vector<int> blocks(nums);

    for (int i = 0; i < nums; ++i)
        std::cin >> blocks[i];

    std::sort(blocks.begin(), blocks.end());

    int horizontal = 0, ans = nums;
    for (int i = 0; i < nums; ++i) {
        horizontal = blocks[i];
        int remaining = nums - i - 1;
        ans = std::min(ans, horizontal + remaining);
    }

    std::cout << ans << std::endl;

    return 0;
}