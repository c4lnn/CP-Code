class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int ret = INT_MAX;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[(startIndex + i) % n] == target) {
                ret = min({ret, i, n - i});
            }
        }
        return ret == INT_MAX ? - 1 : ret;
    }
};