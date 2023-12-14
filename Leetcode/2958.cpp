class Solution {
public:
    int maxSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        int ret = 0;
        std::unordered_map<int, int> cnt;
        for (int l = 0, r = 0; r < n; r++) {
            cnt[a[r]]++;
            while (l <= r && cnt[a[r]] > k) {
                cnt[a[l++]]--;
            }
            ret = std::max(ret, r - l + 1);
        }
        return ret;
    }
};