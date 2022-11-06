class Solution {
public:
    int subarrayGCD(vector<int>& a, int k) {
        int ret = 0;
        for (int i = 0; i < a.size(); i++) {
            int t = 0;
            for (int j = i; j < a.size(); j++) {
                t = __gcd(t, a[j]);
                if (t == k) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};