class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += possible[i] ? 1 : -1;
        }
        for (int i = 0, t = 0; i < n - 1; i++) {
            t += possible[i] ? 1 : -1;
            if (t > sum - t) {
                return i + 1;
            }
        }
        return -1;
    }
};