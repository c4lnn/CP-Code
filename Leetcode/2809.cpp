class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        std::vector<int> a(n);
        std::iota(a.begin(), a.end(), 0);
        std::sort(a.begin(), a.end(), [&](int i, int j) -> bool {
            return nums2[i] < nums2[j];
        });
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + nums1[a[i - 1]] + j * nums2[a[i - 1]]);
            }
        }
        long long sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        long long sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i <= n; i++) {
            if (sum1 + i * sum2 - dp[n][i] <= x) {
                return i;
            }
        }
        return - 1;
    }
};