class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<int, int>> s, t;
        for (int i = 0 ; i < start.size(); i++) {
            if (start[i] == 'L') {
                s.emplace_back(0, i);
            } else if (start[i] == 'R') {
                s.emplace_back(1, i);
            }
        }
        for (int i = 0 ; i < start.size(); i++) {
            if (target[i] == 'L') {
                t.emplace_back(0, i);
            } else if (target[i] == 'R') {
                t.emplace_back(1, i);
            }
        }

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i].first != t[i].first || s[i].first == 0 && s[i].second < t[i].second || s[i].first == 1 && s[i].second > t[i].second) {
                return false;
            }
        }
        return true;
    }
};