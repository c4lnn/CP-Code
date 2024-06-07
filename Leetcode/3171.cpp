class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = INT_MAX;
        std::vector<int> cnt(31);
        for (int l = 0, r = 0; r < n; r++) {
            int now = 0;
            for (int i = 0; i < 31; i++) {
                cnt[i] += (nums[r] >> i) & 1;
                if (cnt[i] == r - l + 1) {
                    now += 1 << i;
                }
            }
            ret = std::min(ret, std::abs(k - now));
            while (now < k && l < r) {
                now = 0;
                for (int i = 0; i < 31; i++) {
                    cnt[i] -= (nums[l] >> i) & 1;
                    if (cnt[i] == r - l) {
                        now += 1 << i;
                    }
                }
                ret = std::min(ret, std::abs(k - now));
                l++;
            }
        }
        return ret;
    }
};