#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n, m;
        std::cin >> n >> m;
        if (n == m) {
            std::cout << "YES" << '\n';
        } else if (n < m) {
            std::cout << "NO" << '\n';
        } else {
            int t = n;
            int cnt3 = 0;
            while (t % 3 == 0) {
                cnt3++;
                t /= 3;
            }
            bool f = false;
            for (int i = 1; i <= cnt3; i++) {
                n /= 3;
                if (!n) break;
                if (m % n == 0) {
                    int q = m / n;
                    if ((q & (q - 1)) == 0 && q <= (1 << cnt3)) {
                        f = true;
                        break;
                    }
                }
            }
            std::cout << (f ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}