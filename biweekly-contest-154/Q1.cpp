// https://leetcode.com/contest/biweekly-contest-154/problems/minimum-operations-to-make-array-sum-divisible-by-k/description

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % k;
    }
};