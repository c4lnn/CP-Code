class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int ret = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            if (rungs[i] - (pre + dist) > 0) {
                int add = (rungs[i] - (pre + dist) + dist - 1) / dist;
                ret += add;
            }
            pre = rungs[i];
        }
        return ret;
    }
};