class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        vector<long long> sum(a.size());
        sum[0] = a[0];
        for (int i = 1; i < a.size(); i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        vector<int> ret;
        for (int i = 0; i < a.size(); i++) {
            if (i - k < 0 || i + k >= a.size()) {
                ret.push_back(-1);
            }
            else if (i - k == 0) {
                ret.push_back(sum[i + k] / (2 * k + 1));
            }
            else {
                ret.push_back((sum[i + k] - sum[i - k - 1]) / (2 * k + 1));
            }
        }
        return ret;
    }
};