class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        long long ret = 0;
        vector<int> vis(n);
        for (int i = 0; i < k; i++) {
            if (vis[i]) continue;
            vector<int> vec;
            for (int j = i; !vis[j]; j = (j + k) % n) {
                vec.push_back(arr[j]);
                vis[j] = true;
            }
            sort(vec.begin(), vec.end());
            int mid = vec[vec.size() / 2];
            for (int i = 0; i < vec.size(); i++) {
                ret += abs(vec[i] - mid);
            }
        }
        return ret;
    }
};