class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (auto x : numsDivide) {
            g = __gcd(x ,g);
        }
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (auto x : nums) {
            if (g % x == 0) {
                break;
            } else {
                ++ret;
            }
        }
        return ret == nums.size() ? -1 : ret;
    }
};