class Solution {
public:
    int findValidSplit(vector<int>& a) {
        int n = a.size(), mx = 1e6;

        vector<vector<int>> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 2; j * j <= a[i]; j++) {
                if (a[i] % j == 0) {
                    f[i].push_back(j);
                    while (a[i] % j == 0) a[i] /= j;
                }
            }
            if (a[i] > 1) f[i].push_back(a[i]);
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (auto p : f[i]) {
                mp[p].push_back(i);
            }
        }

        vector<int> cnt(n);
        for (auto [_, v] : mp) {
            ++cnt[v[0]];
            --cnt[v.back()];
        }

        for (int i = 0; i < n - 1; i++) {
            if (i) cnt[i] += cnt[i - 1];
            if (cnt[i] == 0) return i;
        }

        return -1;
    }
};