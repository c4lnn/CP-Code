class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
        long long ret = 0;
        for (int i = 0, l = -1, pos_mn = -1, pos_mx = -1; i < a.size(); i++) {
            if (a[i] < minK || a[i] > maxK) {
                pos_mn = pos_mx = l = -1;
                continue;
            }
            
            if (l == -1) {
                l = i;
            }
            if (a[i] == minK) {
                pos_mn = i;
            }
            if (a[i] == maxK) {
                pos_mx = i;
            }
            if (pos_mn != -1 && pos_mx != -1) {
                ret += min(pos_mn, pos_mx) - l + 1;
            }
        }
        return ret;
    }
};