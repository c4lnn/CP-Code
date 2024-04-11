class Solution {
public:
    int numberOfPairs(vector<vector<int>>& a) {
        int n = a.size();
        std::vector<int> b;
        for (int i = 0; i < n; i++) {
            b.push_back(a[i][0]);
            b.push_back(a[i][1]);
        }
        std::sort(b.begin(), b.end());
        b.resize(std::unique(b.begin(), b.end()) - b.begin());
        int m = b.size();
        std::vector<std::vector<int>> c(m + 2, std::vector<int>(m + 2)), sum(m + 2, std::vector<int>(m + 2));
        for (int i = 0; i < n; i++) {
            a[i][0] = std::lower_bound(b.begin(), b.end(), a[i][0]) - b.begin() + 1;
            a[i][1] = std::lower_bound(b.begin(), b.end(), a[i][1]) - b.begin() + 1;
            c[a[i][0]][a[i][1]]++;
        }
        std::vector<std::pair<int, int>> d;
        int ret = 0;
        for (int i = m; i; i--) {
            for (int j = 1; j <= m; j++) {
                sum[j][i] = c[j][i] + sum[j][i + 1] + sum[j - 1][i] - sum[j - 1][i + 1];
                if (c[j][i]) {
                    for (auto [x, y] : d) {
                        if (y >= i && x <= j && sum[j][i] - sum[x - 1][i] - sum[j][y + 1] + sum[x - 1][y + 1] == 2) {
                            ret++;
                        }
                    }
                    d.emplace_back(j, i);
                }
            }
        }
        return ret;
    }
};