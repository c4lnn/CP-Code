class Solution {
public:
    int minimumOperations(vector<int>& a) {
        int n = a.size();
        std::vector<int> cnt(101);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        int tot = 0;
        for (int i = 1; i <= 100; i++) {
            tot += cnt[i] > 1;
        }
        if (tot == 0) {
            return 0;
        }
        int ret = 0;
        for (int i = 0; i * 3 < n; i++) {
            ++ret;
            for (int j = 0; j < 3; j++) {
                int idx = i * 3 + j;
                if (idx >= n) {
                    break;
                }
                if (--cnt[a[idx]] == 1) {
                    --tot;
                }
            }
            if (tot == 0) {
                break;
            }
        }
        return ret;
    }
};