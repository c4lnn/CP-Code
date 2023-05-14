class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 1; i <= 9; i++) {
            int cnt = 0;
            for (auto x : nums1) {
                if (x == i) ++cnt;
            }
            for (auto x : nums2) {
                if (x == i) ++cnt;
            }
            if (cnt == 2) return i;
        }
        int a1= 10, a2 = 10;
        for (auto x : nums1) {
            a1 = min(a1, x);
        }
        for (auto x : nums2) {
            a2 = min(a2, x);
        }

        if (a1 > a2) return a2 * 10 + a1;
        return a1 * 10 + a2;
    }
};