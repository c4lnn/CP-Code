class Solution {
public:
    int countDistinctIntegers(vector<int>& a) {
        set<int> s;
        for (auto x : a) {
            s.insert(x);
            int d = 0;
            while(x) {
                d = d * 10 + x % 10;
                x /= 10;
            }
            s.insert(d);
        }
        return s.size();
    }
};