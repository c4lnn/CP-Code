class Solution {
public:
    long long beautifulSubarrays(vector<int>& a) {
        int n = a.size();
        long long ret = 0;
        vector<int> dp(n + 1);
        unordered_map<int ,int> mp;
        mp[0]++;
        for (int i = 0; i < n; i++) {
            dp[i] = i == 0 ? 0 : dp[i - 1];
            for (int j = 0; j < 21; j++) {
                if (a[i] & (1 << j)) {
                    dp[i] ^= (1 << j);
                }
            }
            if (mp.count(dp[i])) {
                ret += mp[dp[i]];
            }
            mp[dp[i]]++;
        }
        return ret;
    }
};