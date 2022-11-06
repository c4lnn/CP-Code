class Solution {
public:
    long long makeSimilar(vector<int>& a, vector<int>& t) {
        deque<int> odd, even;
        sort(a.begin(), a.end());
        sort(t.begin(), t.end());
        for (auto x : t) {
            if (x & 1) {
                odd.push_back(x);
            } else {
                even.push_back(x);
            }
        }
        long long cnt_sub = 0, cnt_add = 0, ret = 0;
        for (int i = 0; i < a.size(); i++) {
            int x;
            if (a[i] & 1) {
                x = odd.front();
                odd.pop_front();
            } else {
                x = even.front();
                even.pop_front();
            }
            if (a[i] > x) {
                int diff = (a[i] - x) / 2;
                if (cnt_sub >= diff) {
                    cnt_sub -= diff;
                } else {
                    ret += diff - cnt_sub;
                    cnt_add += diff - cnt_sub;
                    cnt_sub = 0;
                }
            } else {
                int diff = (x - a[i]) / 2;
                if (cnt_add >= diff) {
                    cnt_add -= diff;
                } else {
                    ret += diff - cnt_add;
                    cnt_sub += diff - cnt_add;
                    cnt_add = 0;
                }
            }
        }
        return ret;
    }
};