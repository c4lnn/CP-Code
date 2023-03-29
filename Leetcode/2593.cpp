class Solution {
public:
    long long findScore(vector<int>& a) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < a.size(); i++) {
            q.emplace(a[i], i);
        }
        long long ret = 0;
        vector<int> f(a.size() + 1);
        while (q.size()) {
            auto t = q.top();
            q.pop();
            if (f[t.second]) continue;
            ret += t.first;
            f[t.second] = 1;
            if (t.second - 1 >= 0) f[t.second - 1] = 1;
            if (t.second + 1 < a.size()) f[t.second + 1] = 1;
        }
        return ret;
    }
};