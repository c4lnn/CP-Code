class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ret(2);
        for (int i = 0; n; i++) {
            if (n & 1) {
                ret[i % 2]++;
            }
            n >>= 1;
        }
        return ret;
    }
};