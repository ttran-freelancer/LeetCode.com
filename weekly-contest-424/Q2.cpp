// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-i/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int, int> mp;
        for (int i = 0; i < queries.size(); i++) {
            mp[queries[i][0]]++;
            mp[queries[i][1]+1]--;
        }

        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += mp[i];
            if (nums[i] > prefixSum) {
                return false;
            }
        }

        return true;
    }
};