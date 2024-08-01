class Solution {
public:
    string clearStars(string s) {
        auto cmp = [](const std::pair<int ,int>& a, const std::pair<int ,int>& b) -> bool {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q;
        int n = s.size();
        std::vector<int> del(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (q.size()) {
                    del[q.top().second] = 1;
                    q.pop();
                }
            } else {
                q.emplace(s[i] - 'a', i);
            }
        }
        std::string ret;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !del[i]) {
                ret += s[i];
            }
        }
        return ret;
    }
};