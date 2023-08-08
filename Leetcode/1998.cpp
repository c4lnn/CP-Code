class Solution {
public:
    struct DSU {
        DSU(int n) : fa(n) {
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
        }

        int find(int x) {
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        }

        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            fa[x] = y;
        }

        std::vector<int> fa;
    };
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(100001);

        for (auto x : nums) {
            int d = x;
            for (int i = 2; i * i <= d; i++) {
                if (d % i == 0) {
                   dsu.merge(x, i);
                   while (d % i == 0) d /= i;
                }
            }
            if (d > 1) dsu.merge(x, d);
        }

        auto vec = nums;
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; i++) {
            if (dsu.find(vec[i]) != dsu.find(nums[i])) {
                return false;
            }
        }

        return true;
    }
};