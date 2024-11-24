// https://leetcode.com/problems/minimum-positive-sum-subarray/description/
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);

        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + l; j <= i + r && j <= n; j++) {
                if (prefixSum[j] - prefixSum[i] > 0) {
                     ans = min(ans, prefixSum[j] - prefixSum[i]);   
                }
            }
        }

        return ans != INT_MAX ? ans : -1;
    }
};