class Solution {
public:
    int subarrayLCM(vector<int>& a, int k) {
        int ret = 0;
        for (int i = 0; i < a.size(); i++) {
            int lcm = a[i];
            for (int j = i; j < a.size(); j++) {
                lcm = lcm * a[j] / __gcd(lcm, a[j]);
                if (lcm > k) {
                    break;
                } else if (lcm == k) {
                    ++ret;
                }
            }
        }
        return ret;
    }
};