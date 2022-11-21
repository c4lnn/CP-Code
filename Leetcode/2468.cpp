class Solution {
public:
    vector<string> splitMessage(string s, int limit) {
        vector<string> ret;
        int mn = INT_MAX;
        int n = s.size();
        for (int i = 1; i <= 4; i++) {
            int t = n;
            for (int j = 1;; j++) {
                int sz = limit - i - 3 - to_string(j).size();
                if (sz <= 0) {
                    break;
                }
                if (t <= sz) {
                    if (i == to_string(j).size() && j < mn) {
                        mn = j;
                    }
                    break;
                }
                t -= sz;
            }
        }
        int l = 0;
        string s_mn = to_string(mn);
        if (mn != INT_MAX) {
            for (int i = 1; i <= mn; i++) {
				string s_i = to_string(i);
                int len = min(n - l, int(limit - 3 - s_mn.size() - s_i.size()));
                ret.push_back(s.substr(l, len) + "<" + s_i + "/" + s_mn + ">");
                l += len;
            }
        }
		return ret;
    }
};