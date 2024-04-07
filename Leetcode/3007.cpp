class Solution {
public:
    long long calc(long long n, int x) {
        long long ret = 0;
        long long d = 0;
        for (int i = x - 1; n >> i; i++) {
            if ((i + 1) % x == 0) {
                if (n & (1ll << i)) {
                    ret += ((n >> (i + 1)) << i) + n - ((n >> i) << i) + 1;
                } else {
                    ret += (((n >> (i + 1)) - 1) << i) + (1ll << i) - 1 + 1;
                }
            }
        }
        return ret;
    }

    long long findMaximumNumber(long long k, int x) {
        long long l = 0, r =  1e15;
        while (l < r) {
            long long mid = l + r + 1 >> 1;
            if (calc(mid, x) <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};