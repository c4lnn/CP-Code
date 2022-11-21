class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> vis(26);
        for (auto c : s) {
            if (vis[c - 'a']) {
                return c;
            } else {
                vis[c - 'a'] = true;
            }
        }
        return 'a';
    }
};