class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int ret = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (std::abs(s[i] - s[i - 1]) <= 1) {
                ++ret;
                ++i;
            }
        }
        return ret;
    }
};