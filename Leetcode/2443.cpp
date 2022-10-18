class Solution {
public:
    bool sumOfNumberAndReverse(int n) {
        for (int i = 0; i <= n; i++) {
            int d = 0, j = i;
            while (j) {
                d = d * 10 + j % 10;
                j /= 10;
            }
            if (i + d == n) {
                return true;
            }
        }
        return false;
    }
};