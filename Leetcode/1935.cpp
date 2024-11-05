class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        std::vector<int> st(26);
        for (auto c : brokenLetters) {
            st[c - 'a'] = 1;
        }
        int ret = 0;
        bool f = true;
        for (auto c : text) {
            if (c == ' ') {
                ret += f;
                f = true;
            } else if (st[c - 'a']) {
                f = false;
            }
        }
        ret += f;
        return ret;
    }
};