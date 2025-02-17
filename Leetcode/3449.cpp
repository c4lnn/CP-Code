class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        long long l = 0, r = 5e14;
        int n = points.size();
        auto check = [&](long long mid) -> bool {
            long long tot = 0, pre = 0;
            int pre_idx = -1;
            for (int i = 0; i < n; i++) {
                long long cnt = (mid + points[i] - 1) / points[i];
                if (cnt - 1 == pre) {
                    tot += i - pre_idx;
                    pre = 0;
                    pre_idx = i;
                } else if (cnt <= pre) {
                    pre = 0;
                } else {
                    tot += (i - pre_idx) + (cnt - pre - 1) * 2;
                    pre = cnt - pre - 1;
                    pre_idx = i;
                }
                if (tot > m) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            long long mid = l + r + 1 >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};