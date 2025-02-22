class Solution {
public:
    int maxDistinctElements(vector<int>& a, int k) {
        std::sort(a.begin(), a.end());
        int n = a.size();
        int l = a[0] - k;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (l - a[i] < -k) {
                l = a[i] - k;
            }
            if (l - a[i] >= -k && l - a[i] <= k) {
                ret++;
                l++;
            }
        }
        return ret;
    }
};