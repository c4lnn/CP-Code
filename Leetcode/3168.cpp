class Solution {
public:
    int minimumChairs(string s) {
        int ret = 0, cnt = 0;
        for (auto c : s) {
            if (c == 'E') {
                if (!cnt) {
                    ++ret;
                } else {
                    --cnt;
                }
            } else {
                ++cnt;
            }
        }
        return ret;
    }
};