class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        std::vector<int> cnt(200001);
        for (auto x : changed) {
            cnt[x]++;
        }
        std::sort(changed.begin(), changed.end());
        std::vector<int> ret;
        for (auto x : changed) {
            if (x == 0 && cnt[0] > 1 || x && cnt[x] && cnt[x * 2]) {
                cnt[x]--;
                cnt[x * 2]--;
                ret.push_back(x);
            }
        }
        return ret.size() * 2 == changed.size() ? ret : std::vector<int>();
    }
};