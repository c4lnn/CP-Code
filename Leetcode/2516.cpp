class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ret = INT_MAX;
        vector<int> cnt(3);
        for (int i = 0; i < n; i++) {
            ++cnt[s[i] - 'a'];
        }
        if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
            ret = n;
        }
        for (int l = 0, r = 0; r < n; r++) {
            --cnt[s[r] - 'a'];
            while (l < r && (cnt[0] < k || cnt[1] < k || cnt[2] < k)) {
                ++cnt[s[l++] - 'a'];
            }
            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ret = min(ret, n - (r - l + 1));
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};