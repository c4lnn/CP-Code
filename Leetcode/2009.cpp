class Solution {
public:
    int minOperations(vector<int>& nums) {
        int m = nums.size();
        std::sort(nums.begin(), nums.end());
        nums.resize(std::unique(nums.begin(), nums.end()) - nums.begin());
        int n = nums.size();
        int ret = m - 1;
        for (int l = 0, r = 1; r < n; r++) {
            while(l < r && nums[r] - nums[l] > m - 1) {
                l++;
            }
            ret = std::min(ret, m - (r - l + 1));
        }
        return ret;
    }
};