// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-ii/

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, int> mp;

        int prefixSum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += mp[i];
            while (nums[i] > prefixSum && ans < queries.size()) {
                ans++;
                mp[queries[ans-1][0]] += queries[ans-1][2];
                mp[queries[ans-1][1] + 1] -= queries[ans-1][2];
                if (queries[ans-1][0] <= i && i <= queries[ans-1][1]) {
                    prefixSum += queries[ans-1][2];
                }
            }
            if (nums[i] > prefixSum) {
                return -1;
            }
        }

        return ans;
    }
};