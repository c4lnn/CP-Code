class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ret = -1;
        unordered_map<int, int> mp;
        for (auto x : nums) {
            int sum = 0, d = x;
            while (d) {
                sum += d % 10;
                d /= 10;
            }
            if (mp.count(sum)) {
                ret = max(ret, x + mp[sum]);
                if (x > mp[sum]) {
                    mp[sum] = x;
                }
            } else {
                mp[sum] = x;
            }
        }
        return ret;
    }
};