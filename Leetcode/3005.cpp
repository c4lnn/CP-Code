class Solution {
public:
    int maxFrequencyElements(vector<int>& a) {
        std::vector<int> cnt(101);
        for (auto x : a) {
            cnt[x]++;
        }
        int max = 0, ret = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] > max) {
                ret = max = cnt[i];
            } else if (cnt[i] == max) {
                ret += cnt[i];
            }
        }
        return ret;
    }
};