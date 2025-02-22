class Solution {
public:
    std::unordered_map<int, int> min;
    int minDays(int n) {
        if (min.count(n)) {
            return min[n];
        }
        if (n <= 1) {
            return min[n] = n;
        }
        return min[n] = std::min(minDays(n / 2) + n % 2, minDays(n / 3) + n % 3) + 1;
    }
};