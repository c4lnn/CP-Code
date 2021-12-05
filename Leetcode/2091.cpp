class Solution {
public:
    int minimumDeletions(vector<int>& x) {
        int mn = INT_MAX, mx = INT_MIN, a, b;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] < mn) {
                mn = x[i];
                a = i;
            }
            if (x[i] > mx) {
                mx = x[i];
                b = i;
            }
        }
        if (a > b) {
            swap(a, b);
        }
        ++a;
        ++b;
        return min({b, (int)x.size()- a + 1, a + (int)x.size() - b + 1});
    }
};