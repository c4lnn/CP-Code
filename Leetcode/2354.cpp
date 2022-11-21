class Solution {
public:
    long long countExcellentPairs(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        vector<int> popcount(a.size()), cnt(31);
        long long ret = 0;
        for (int i = 0; i < a.size(); i++) {
            ++cnt[popcount[i] = __builtin_popcount(a[i])];
        }
        for (int i = 1; i < 31; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < a.size(); i++) {
            ret += cnt[30] - cnt[min(30, max(0, k - popcount[i] - 1))];
        }
        return ret;
    }
};