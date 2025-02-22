class Solution {
public:
    int minOperations(int n) {
        int mid = n;
        n = n / 2;
        return n * (mid - 1) - n * (n - 1);
    }
};