class Solution {
public:
    int distinctAverages(vector<int>& a) {
        sort(a.begin(), a.end());
        set<double> s;
        int n = a.size();
        for (int i = 0; i < n / 2; i++) {
            s.insert(a[i] + a[a.size() - 1 - i]);
        }
        return s.size();
    }
};