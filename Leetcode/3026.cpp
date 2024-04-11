#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        long long sum = 0;
        std::map<int, long long> min;
        long long ret = -1e18;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (min.count(a[i] - k)) {
                ret = std::max(ret, sum - min[a[i] - k]);
            }
            if (min.count(a[i] + k)) {
                ret = std::max(ret, sum - min[a[i] + k]);
            }
            if (!min.count(a[i])) {
                min[a[i]] = sum - a[i];
            } else {
                min[a[i]] = std::min(min[a[i]], sum - a[i]);
            }
        }
        return ret == -1e18 ? 0 : ret;
    }
};