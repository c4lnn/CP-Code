class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ret = 0;
        std::vector<int> a(n + 1);
        for (int i = n / 2; i; i--) {
            ret += std::abs(cost[i * 2 - 1] - cost[i * 2]);
            cost[i - 1] += std::max(cost[i * 2 - 1], cost[i * 2]);
        }
        return ret;
    }
};