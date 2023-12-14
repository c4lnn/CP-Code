class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        std::vector<std::vector<int>> w(n, std::vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; i++) {
            w[i][i] = 0;
        }
        for (const auto& e : roads) {
            w[e[0]][e[1]] = w[e[1]][e[0]] = std::min(w[e[0]][e[1]], e[2]);
        }
        int ret = 0;
        for (int i = 0; i < 1 << n; i++) {
            auto dist = w;
            std::vector<int> vec;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    vec.push_back(j);
                }
            }
            for (auto k : vec) {
                for (auto u : vec) {
                    for (auto v : vec) {
                        dist[u][v] = std::min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
            bool f = true;
            for (auto u : vec) {
                for (auto v : vec) {
                    if (u != v) {
                        if (dist[u][v] > maxDistance) {
                            f = false;
                            break;
                        }
                    }
                }
                if (!f) {
                    break;
                }
            }
            ret += f;
        }
        return ret;
    }
};