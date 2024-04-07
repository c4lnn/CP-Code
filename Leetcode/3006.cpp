class Solution {
public:
    std::vector<int> nxt;
    void get_next(const std::string &t) {
        int i = 0, j = -1;
        nxt[0] = -1;
        while (i < t.size()) {
            if (j == -1 || t[i] == t[j]) {
                ++i, ++j;
                if (t[i] != t[j]) {
                    nxt[i] = j;
                }
                else {
                    nxt[i] = nxt[j];
                }
            } else {
                j = nxt[j];
            }
        }
    }
    void kmp(const std::string &s, const std::string &t, std::vector<int>& idx) {
        get_next(t);
        int i = 0, j = 0;
        while (i < s.size()) {
            if (j == -1 || s[i] == t[j]) {
                ++i, ++j;
                if (j == t.size()) {
                    idx.push_back(i - j);
                    j = nxt[j]; // 匹配成功
                }
            } else {
                j = nxt[j];
            }
        }
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        std::vector<int> idx_a, idx_b, ret;
        nxt.resize(s.size() + 1);
        if (a.size() <= s.size()) {
            kmp(s, a, idx_a);
        }
        if (b.size() <= s.size()) {
            kmp(s, b, idx_b);
        }
        for (auto x : idx_a) {
            int l = std::lower_bound(idx_b.begin(), idx_b.end(), x - k) - idx_b.begin();
            int r = std::upper_bound(idx_b.begin(), idx_b.end(), x + k) - idx_b.begin() - 1;
            if (l <= r) {
                ret.push_back(x);
            }
        }
        return ret;
    }
};