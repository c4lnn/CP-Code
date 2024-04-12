class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        std::unordered_map<int ,int> mp;
        int ret = 0;
        for (auto x : nums) {
            ret += mp[x + k] + mp[x - k];
            mp[x]++;
        }
        return ret;
    }
};