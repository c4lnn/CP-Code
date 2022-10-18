class Solution {
public:
    int findMaxK(vector<int>& a) {
        int ret = -1;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] == -a[j]) {
                    ret = max(ret, abs(a[i]));
                }
            }
        }
        return ret;
    }
};