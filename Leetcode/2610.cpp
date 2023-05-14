class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(201);
        for (auto x : nums) {
            cnt[x]++;
        }
        vector<vector<int>> ret;
        for (int i = 0; i < 200; i++) {
            vector<int> vec;
            for (int j = 1; j <= 200; j++) {
                if (cnt[j]) {
                    vec.push_back(j);
                    --cnt[j];
                }
            }
            if(vec.size()) ret.push_back(vec);
        }
        return ret;
    }
};