class Solution {
public:
    const int N = 1e6 + 5;
    long long minCost(vector<int>& a, vector<int>& c) {
        std::vector<long long> val(N);
        for (int i = 0; i < c.size(); i++) {
            val[a[i]] += c[i];
        }
        for (int i = 1; i <= 1e6; i++) {
            val[i] += val[i - 1];
        }
        long long ret = LLONG_MAX, l = 0,  r = 0;
        for (int i = 0; i < c.size(); i++) {
            r += 1ll * c[i] * a[i];
        }
        for (int i = 1; i <= 1e6; i++) {
            l += val[i - 1];
            r -= val[1000000] - val[i - 1];
            ret = min(ret, l + r);
        }
        return ret;
    }
};