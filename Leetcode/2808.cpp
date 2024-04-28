class Solution {
public:
    int minimumSeconds(vector<int>& a) {
        int n = a.size();
        int ret = INT_MAX;
        std::unordered_map<int, std::vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].push_back(i);
        }
        for (const auto& [x, vec] : mp) {
            int max = 0;
            for (int i = 1; i < vec.size(); i++) {
                max = std::max(max, vec[i] - vec[i - 1]);
            }
            max = std::max(max, vec.front() + n - vec.back());
            ret = std::min(ret, max / 2);
        }
        return ret;
    }
};