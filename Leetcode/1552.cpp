class Solution {
public:
    int maxDistance(vector<int>& a, int m) {
        std::sort(a.begin(), a.end());
        int l = 1, r = a.back() - a.front();
        auto check = [&](int mid) -> bool {
            int cnt = 1, pre = a[0];
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - pre >= mid) {
                    if (++cnt == m) {
                        return true;
                    }
                    pre = a[i];
                }
            }
            return false;
        };
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};