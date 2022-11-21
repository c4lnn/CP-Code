class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int n = g.size(), ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int t = 0;
                for (int k = 0; k < n; k++) {
                    if (g[i][k] == g[k][j]) {
                        ++t;
                    } else {
                        break;
                    }
                }
                if (t == n) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};