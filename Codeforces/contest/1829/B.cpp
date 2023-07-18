#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n;
        std::cin >> n;
        int cnt = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            if (x == 0) {
                res = std::max(res, ++cnt);
            } else {
                cnt = 0;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}