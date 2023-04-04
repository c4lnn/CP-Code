class Solution {
public:
    int findSmallestInteger(vector<int>& a, int value) {
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++) {
            a[i] = (a[i] % value + value) % value;
            if (mp.count(a[i])) {
                mp[a[i]] += value;
                a[i] = mp[a[i]];
            }
            mp[a[i]] = a[i];
        }
        for (int i = 0;; i++) {
            if (!mp.count(i)) {
                return i;
            }
        }
        return 0;
    }
};