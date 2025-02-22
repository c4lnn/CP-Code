class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        std::vector<long long> fl(n), fr(n);
        std::stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && maxHeights[stk.top()] > maxHeights[i]) {
                stk.pop();
            }
            fl[i] = stk.size() ? fl[stk.top()] + 1ll * (i - stk.top()) * maxHeights[i] : 1ll * (i + 1) * maxHeights[i];
            stk.push(i);
        }
        while (stk.size()) {
            stk.pop();
        }
        for (int i = n - 1; ~i; i--) {
            while (stk.size() && maxHeights[stk.top()] > maxHeights[i]) {
                stk.pop();
            }
            fr[i] = stk.size() ? fr[stk.top()] + 1ll * (stk.top() - i) * maxHeights[i]: 1ll * (n - i) * maxHeights[i];
            stk.push(i);
        }
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            ret = std::max(ret, fl[i] + fr[i] - maxHeights[i]);
        }
        return ret;
    }
};