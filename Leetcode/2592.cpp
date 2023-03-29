class Solution {
public:
    int maximizeGreatness(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        queue<int> stk;
        int ret = 0;
        for (auto x : a) {
            if (stk.size() && x > stk.front()) {
                ++ret;
                stk.pop();
            }
            stk.emplace(x);
        }
        return ret;
    }
};