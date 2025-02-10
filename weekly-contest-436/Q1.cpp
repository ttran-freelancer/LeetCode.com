// https://leetcode.com/problems/sort-matrix-by-diagonals/description/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int k = 0; k < n; k++) {
            for (int i = 0; k + i < n; i++) {
                for (int j = i + 1; k + j < n; j++) {
                    if (grid[k + i][i] < grid[k + j][j]) {
                        swap(grid[k + i][i] , grid[k + j][j]);
                    }
                }
            }
        }

        for (int k = 1; k < n; k++) {
            for (int i = 0; k + i < n; i++) {
                for (int j = i + 1; k + j < n; j++) {
                    if (grid[i][i + k] > grid[j][j + k]) {
                        swap(grid[i][i + k] , grid[j][j + k]);
                    }
                }
            }
        }

        return grid;
    }
};