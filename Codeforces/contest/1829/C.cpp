#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n;
        std::cin >> n;
        int res = 0x3f3f3f3f;
        int t1 = 0x3f3f3f3f, t2 = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            if (b == 11) {
                res = std::min(res, a);
            } else if (b == 10) {
                t1 = std::min(t1, a);
            } else if (b == 1) {
                t2 = std::min(t2, a);
            }
        }
        res = std::min(res, t1 + t2);
        std::cout << (res == 0x3f3f3f3f ? -1 : res) << std::endl;
    }
    return 0;
}