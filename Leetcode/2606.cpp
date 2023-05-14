class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26);
        for (int i = 0;i < 26; i++) {
            v[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            v[chars[i] - 'a'] = vals[i];
        }
        int res = 0, sum = 0, mn = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += v[s[i] - 'a'];
            res = max(res, sum - mn);
            mn = min(mn, sum);
        }
        return res;
    }
};