class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        for (int i = 1;; i++) {
            if (i * (i + 1) / 2 > grades.size()) {
                return i - 1;
            }
        }
    }
};