class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end(), [](const std::vector<int>& a, const std::vector<int>& b) -> bool {
            return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
        });
        int max = 0, ret = 0;
        for (const auto& meeting : meetings) {
            if (meeting[0] > max) {
                ret += meeting[0] - max - 1;
            }
            max = std::max(max, meeting[1]);
        }
        return ret + days - max;
    }
};