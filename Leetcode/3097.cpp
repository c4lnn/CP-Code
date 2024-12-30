class Solution {
public:
    int minimumSubarrayLength(vector<int>& a, int k) {
        int n = a.size();
        int ret = INT_MAX;
        for (int l = 0, r = 0, top = 0, right = 0; r < n; r++) {
            right |= a[r];
            while (l <= r && (a[l] | right) >= k) {
                ret = std::min(ret, r - l + 1);
                l++;
                if (l > top) {
                    top = r;
                    right = 0;
                    for (int i = r - 1; i >= l; i--) {
                        a[i] |= a[i + 1];
                    }
                }
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};