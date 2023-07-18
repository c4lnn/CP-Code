#include <bits/stdc++.h>

int main() {
    int cas;
    std::cin >> cas;
    while (cas--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> a[i][j];
            }
        }

        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0 || vis[i][j] == true) return 0;
            vis[i][j] = true;
            return a[i][j] + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
        };

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false) {
                    res = std::max(res, dfs(i, j));
                }
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}