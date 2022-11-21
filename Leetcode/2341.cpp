class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int>cnt(101);
        for (auto x : nums) {
            ++cnt[x];
        }
        vector<int> ret(2);
        for (int i = 0; i <= 100; i++) {
            ret[0] += cnt[i] / 2;
            ret[1] += cnt[i] % 2;
        }
        return ret;
    }
};