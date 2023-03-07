class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        int ret = 1, mx_r = -1, mod = 1e9 + 7;
        for (auto& vec : ranges) {
            if (vec[0] > mx_r) {
                ret = ret * 2 % mod;
            }
            mx_r = max(mx_r, vec[1]);
        }
        return ret;
    }
};