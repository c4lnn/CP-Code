class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        map<char, int> mp;
        mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = 1;
        int ret = 0;
        for (int i = left; i <= right; i++) {
            if (mp.count(words[i].front()) && mp.count(words[i].back())) {
                ++ret;
            }
        }
        return ret;
    }
};