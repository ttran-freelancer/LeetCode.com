// https://leetcode.com/contest/weekly-contest-446/problems/make-array-non-decreasing/description

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int mx = 0, ans = 0;
        for (auto num : nums) {
            if (num >= mx) {
                mx = max(mx, num);
                ans++;
            }
        }

        return ans;
    }
};