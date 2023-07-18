#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        std::string s;
        std::cin >> s;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != "codeforces"[i]) {
                ++res;
            }
        }
        std::cout << res << std::endl;
    }

    return 0;
}