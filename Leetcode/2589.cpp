class Solution {
public:
    int findMinimumTime(vector<vector<int>>& a) {
        sort(a.begin(), a.end(),[](const auto& a, const auto& b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
        });
        int n = a.size();
        vector<int> b(2001), sum(2001);
        for (int i = 0; i < n; i++) {
            int t = a[i][2] - (sum[a[i][1]] - sum[a[i][0] - 1]);
            if (t <= 0) { continue; }
            for (int j = a[i][1]; j >= a[i][0] && t > 0; j--) {
                if (b[j] == 0) {
                    b[j] = 1;
                    t--;
                }
            }
            for (int j = a[i][0]; j <= 2000; j++) {
                sum[j] = sum[j - 1] + b[j];
            }
        }
        return sum[2000];
    }
};