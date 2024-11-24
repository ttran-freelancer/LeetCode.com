// https://leetcode.com/problems/minimum-array-sum/description/
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> L(
            n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= op1; j++) {
                for (int l = 0; l <= op2; l++) {
                    L[i + 1][j][l] = L[i][j][l] + nums[i];
                    if (j > 0) {
                        L[i + 1][j][l] = min(
                            L[i + 1][j][l], L[i][j - 1][l] + (nums[i] + 1) / 2);
                    }
                    if (l > 0 && nums[i] >= k) {
                        L[i + 1][j][l] =
                            min(L[i + 1][j][l], L[i][j][l - 1] + (nums[i] - k));
                    }
                    if (j > 0 && l > 0 && nums[i] >= k) {
                        L[i + 1][j][l] = min(L[i + 1][j][l],
                                             L[i][j - 1][l - 1] +
                                                 (nums[i] >= 2 * k - 1
                                                      ? (nums[i] + 1) / 2 - k
                                                      : (nums[i] - k + 1) / 2));
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j <= op1; j++) {
            for (int l = 0; l <= op2; l++) {
                ans = min(ans, L[n][j][l]);
            }
        }
        return ans;
    }
};