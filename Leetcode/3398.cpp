class Solution {
public:
    int minLength(string s, int numOps) {
        std::vector<int> a;
        int len = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                len++;
            } else {
                a.push_back(len);
                len = 1;
            }
        }
        a.push_back(len);
        auto check = [&](int k) -> bool {
            int cnt = 0;
            if (k == 1) {
                for (int i = 0; i < s.size(); i++) {
                    cnt += (s[i] ^ i) & 1;
                }
                return std::min(cnt, int(s.size()) - cnt) <= numOps;
            }
            for (int i = 0; i < a.size(); i++) {
                if (a[i] > k) {
                    cnt += a[i] / (k + 1);
                }
                if (cnt > numOps) {
                    return false;
                }
            }
            return true;
        };
        int l = 1, r = s.size();
        while (l < r) {
            int mid = l + r >> 1;
            int ret = check(mid);
            if (ret) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};