class Solution {
public:
    int maxTotalReward(vector<int>& r) {
        std::sort(r.begin(), r.end());
        r.erase(std::unique(r.begin(), r.end()), r.end());
        int n = r.size();
        std::bitset<100000> b{1};
        for (int i = 0; i < n; i++) {
            b |= b << (100000 - r[i]) >> (100000 - r[i] * 2);
        }
        int ret = 0;
        for (int i = b.size() - 1; ~i; i--) {
            if (b[i]) {
                ret = i;
                break;
            }
        }
        return ret;
    }
};