class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if ((sum += nums[i]) > 0) {
                ++ret;
            }
        }
        return ret;
    }
};