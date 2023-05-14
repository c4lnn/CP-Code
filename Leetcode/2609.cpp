class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt0 = 0, cnt1 = 0, res = 0;
        for (auto c :s) {
            if (c == '0') {
                if (cnt1) cnt0 = cnt1 = 0;
                ++cnt0;
            } else {
                ++cnt1;
                if (cnt0 >= cnt1) {
                    res = max(res, cnt1 * 2);
                }
            }
        }
        return res;
    }
};