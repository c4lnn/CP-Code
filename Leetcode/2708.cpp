class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        long long ret = -1e18;
        for (int i = 1; i < 1 << n; i++) {
            long long p = 1;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    p *= nums[j];
                }
            }
            ret = max(ret, p);
        }
        return ret;
    }
};