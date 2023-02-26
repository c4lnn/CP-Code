class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = 1e9;
        auto check = [&](int mid) -> bool {
            int pre = price[0];
            int cnt = k - 1;
            for (int i = 1; i < price.size(); i++) {
                if (price[i] - pre >= mid) {
                    if (--cnt == 0) {
                        return true;
                    }
                    pre = price[i];
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