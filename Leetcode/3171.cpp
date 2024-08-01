class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = INT_MAX;
        for (int l = 0, r = 0, top = 0, or_r = 0; r < n; r++) {
            or_r |= nums[r];
            while (l <= r && (nums[l] | or_r) > k) {
                ret = std::min(ret, (nums[l] | or_r) - k);
                if (++l > top) {
                    for (int i = r - 1; i >= l; i--) {
                        nums[i] |= nums[i + 1];
                    }
                    top = r;
                    or_r = 0;
                }
            }
            if (l <= r) {
                ret = std::min(ret, k - (nums[l] | or_r));
            }
        }
        return ret;
    }
};