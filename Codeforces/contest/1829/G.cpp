#include <bits/stdc++.h>

int main() {
    std::vector<std::vector<int>> id(1500, std::vector<int>(1500));
    std::vector<long long> sum(1000001);
    for (int i = 0, t= 0;; i++) {
        for (int j = 0; j <= i; j++) {
            id[i][j] = ++t;
            if (i) {
                if (j == 0) sum[t] = sum[id[i - 1][0]];
                else if (j == i) sum[t] = sum[id[i - 1][j - 1]];
                else {
                    sum[t] = sum[id[i - 1][j - 1]] + sum[id[i - 1][j]];
                    if (i - 2 >= 0) sum[t] -= sum[id[i -2][j - 1]];
                }
            }
            sum[t] += 1ll * t * t;
            if (t == 1e6) break;
        }
        if (t == 1e6) break;
    }
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n;
        std::cin >> n;
        std::cout << sum[n] << std::endl;
    }
    return 0;
}