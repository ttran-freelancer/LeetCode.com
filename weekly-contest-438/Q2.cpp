// https://leetcode.com/contest/weekly-contest-438/problems/maximum-sum-with-at-most-k-elements/description/

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        using PII = pair<int, int>;
        priority_queue<PII> pq;

        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push({grid[i][j], i});
            }
        }

        long long ans = 0L;
        while (k--) {
            auto top = pq.top();
            pq.pop();
            if (limits[top.second] > 0) {
                ans += top.first;
                limits[top.second]--;
            } else {
                k++;
            }
        }
        return ans;
    }
};