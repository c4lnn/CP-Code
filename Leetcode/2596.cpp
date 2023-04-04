class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& a) {
        unordered_map<int, pair<int, int>> mp;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[a[i][j]] = {i, j};
            }
        }
        if (a[0][0] != 0) return false;
        const int DIR[8][2] = {-2, -1, 2, -1, -1, -2, 1, -2, -2, 1, 2, 1, -1, 2, 1, 2};
        for (int i = 0; i < n * n - 1; i++) {
            int r1 = mp[i].first, c1 = mp[i].second;
            int r2 = mp[i + 1].first, c2 = mp[i + 1].second;
            bool f = false;
            for (int j = 0; j < 8; j++) {
               if (r1 + DIR[j][0] == r2 && c1 + DIR[j][1] == c2) {
                    f = true;
                    break;
               }
            }
            if (!f) {
                return false;
            }
        }
        return true;
    }
};