class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            std::vector<int> vec;
            for (int j = 0; i + j < n; j++) {
                vec.push_back(grid[i + j][j]);
            }
            std::sort(vec.begin(), vec.end(), std::greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = vec[j];
            }
        }
        for (int i = 1; i < n; i++) {
            std::vector<int> vec;
            for (int j = 0; i + j < n; j ++) {
                vec.push_back(grid[j][i + j]);
            }
            std::sort(vec.begin(), vec.end());
            for (int j = 0; i + j < n; j++) {
                grid[j][i + j] = vec[j];
            }
        }
        return grid;
    }
};