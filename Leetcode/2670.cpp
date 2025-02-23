class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& a) {
        std::vector<int> pre(51), suf(51);
        std::vector<int> ret;
        int pre_cnt = 0, suf_cnt = 0;
        for (auto x : a) {
            if (++suf[x] == 1) {
                suf_cnt++;
            }
        }
        for (auto x : a) {
            if (++pre[x] == 1) {
                pre_cnt++;
            }
            if (--suf[x] == 0) {
                suf_cnt--;
            }
            ret.push_back(pre_cnt - suf_cnt);
        }
        return ret;
    }
};