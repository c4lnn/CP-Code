#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> cnt(n + 1);
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            ++cnt[u];
            ++cnt[v];
        }
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                b = cnt[g[i][0]] - 1;
                for (auto v : g[g[i][0]]) {
                    if (v != i && cnt[v] != 1) {
                        a = cnt[v];
                        break;
                    }
                }
                if (a) break;
            }
        }
        std::cout << a << ' ' << b << std::endl;
    }
    return 0;
}