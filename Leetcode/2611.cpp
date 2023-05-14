class Solution {
public:
    int miceAndCheese(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = {a[i] - b[i], i};
        }
        sort(c.begin(), c.end(), greater<pair<int, int>>());
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int idx = c[i].second;
            if (i < k) ret += a[idx];
            else ret += b[idx];
        }
        return ret;
    }
};