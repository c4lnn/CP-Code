class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.begin(), a.end());
        return max(0, (a[0] + a[1] - a[2] + 1) / 2) + a[2];
    }
};