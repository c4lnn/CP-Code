class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        std::vector<int> a(n), ret;
        int now = 0;
        for (auto v : q) {
            int i = v[0], c = v[1];
            if (i && a[i] && a[i - 1] == a[i] && a[i - 1] != c) {
                now--;
            }
            if (i && a[i - 1] != a[i] && a[i - 1] == c) {
                now++;
            }
            if (i < n - 1 && a[i] && a[i] == a[i + 1] && a[i + 1] != c) {
                now--;
            }
            if (i < n - 1 && a[i] != a[i + 1] && a[i + 1] == c) {
                now++;
            }
            ret.push_back(now);
            a[i] = c;
        }
        return ret;
    }
};