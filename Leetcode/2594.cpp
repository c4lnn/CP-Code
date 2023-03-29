class Solution {
public:
    long long repairCars(vector<int>& a, int n) {
        long long l = 0, r = 1e14;

        auto check = [&](long long mid) -> bool {
            long long sum = 0;
            for (int i = 0; i < a.size(); i++) {
                sum += sqrt(mid / a[i]);
            }
            return sum >= n;
        };

        while (l < r) {
            long long mid = l + r >> 1;
            check(mid) ? r = mid : l = mid + 1;
        }
        return l;
    }
};