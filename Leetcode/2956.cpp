class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& a, vector<int>& b) {
        std::unordered_map<int, bool> mp1, mp2;
        for (auto x : a) {
            mp1[x] = true;
        }
        for (auto x : b) {
            mp2[x] = true;
        }
        std::vector<int> ret(2);
        for (auto x : a) {
            if (mp2.count(x)) {
                ret[0]++;
            }
        }
        for (auto x : b) {
            if (mp1.count(x)) {
                ret[1]++;
            }
        }
        return ret;
    }
};