// https://leetcode.com/contest/weekly-contest-447/problems/path-existence-queries-in-a-graph-i/description

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {   
        vector<int> result(n);
        for (int i = 0; i < nums.size(); i++) {
            int j = upper_bound(nums.begin(), nums.end(), nums[i] + maxDiff) - nums.begin();
            result[i] = j - 1;
        }
        
        int m = queries.size();
        vector<bool> ans(m, true);
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (u == v) continue;
            if (u > v) {
                swap(u, v);
            }
            int r = result[u];
            while (r != result[r]) {
                r = result[r];
            }
            ans[i] = v <= r;
        }

        return ans;
    }
};