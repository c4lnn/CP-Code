class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int n) {
        sort(a.begin(), a.end());
        vector<int> ret;
        for (int i = 0; i < a.size(); i++) {
            if(a[i] == n) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};