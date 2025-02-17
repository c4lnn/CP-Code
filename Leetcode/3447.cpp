class Solution {
public:
    vector<int> assignElements(vector<int>& a, vector<int>& b) {
        int max = *std::max_element(a.begin(), a.end());
        std::vector<std::vector<int>> fac(max + 1);
        for (int i = 1; i <= max; i++) {
            for (int j = i; j <= max; j += i) {
                fac[j].push_back(i);
            }
        }
        std::unordered_map<int, int> mp;
        for (int i = 0; i < b.size(); i++) {
            if (!mp.count(b[i])) {
                mp[b[i]] = i;
            }
        }
        std::vector<int> ret;
        for (int i = 0; i < a.size(); i++) {
            int min = INT_MAX;
            for (auto x : fac[a[i]]) {
                if (mp.count(x)) {
                    min = std::min(min, mp[x]);
                }
            }
            ret.push_back(min == INT_MAX ? -1 : min);
        }
        return ret;
    }
};