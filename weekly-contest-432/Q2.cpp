// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<int>> d = {{0, 1}, {1, 0}};
        vector<vector<vector<int>>> L(m, vector<vector<int>>(n, vector<int>(3, -1e6)));

        L[0][0][2] = coins[0][0];  
        if (coins[0][0] < 0) {
            L[0][0][1] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 2; k++) {
                    int x = i - d[k][0];
                    int y = j - d[k][1];
                    if (x >= 0 && y >= 0) {
                        if (coins[i][j] >= 0) {
                            for (int l = 0; l < 3; l++) {
                                 L[i][j][l] = max(L[i][j][l], L[x][y][l] + coins[i][j]);   
                            }
                        } else {
                            for (int l = 0; l < 3; l++) {
                                 L[i][j][l] = max(L[i][j][l], L[x][y][l] + coins[i][j]);   
                            }
                            for (int l = 1; l < 3; l++) {
                                L[i][j][l-1] = max(L[i][j][l-1], L[x][y][l]);
                            }
                        }
                    }
                }
            }
        }

        return max({L[m-1][n-1][0], L[m-1][n-1][1], L[m-1][n-1][2]});
    }
};