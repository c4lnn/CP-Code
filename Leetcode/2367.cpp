class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - nums[i] != diff) {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] - nums[j] == diff) {
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }
};