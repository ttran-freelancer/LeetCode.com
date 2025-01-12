// https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int direct = 1;
        bool skip = false;
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            if (direct == 1) {
                for (int j = 0; j < n; j++) {
                    if (!skip) { 
                        ans.push_back(grid[i][j]);
                    }
                    skip = !skip;
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    if (!skip) { 
                        ans.push_back(grid[i][j]);
                    }
                    skip = !skip;
                }
            }
            
            direct *= -1;
        }

        return ans;
    }
};