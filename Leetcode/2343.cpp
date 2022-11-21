class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ret;
        for (int i = 0; i < queries.size(); i++) {
            vector<pair<string, int>> v;
            for(int j = 0; j < nums.size(); j++) {
                v.emplace_back(nums[j].substr(nums[j].size() - queries[i][1], queries[i][1]), j);
            }
            sort(v.begin(), v.end());
            ret.push_back(v[queries[i][0] - 1].second);
        }
        return ret;
    }
};