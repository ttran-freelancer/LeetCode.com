// https://leetcode.com/contest/weekly-contest-441/problems/maximum-unique-subarray-sum-after-deletion/description

class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int mx_non_pos = INT_MIN;
        for (auto num : nums) {
            if (num > 0) {
                st.insert(num);
            } else {
                mx_non_pos = max(mx_non_pos, num);
            }
        }

        int sum = accumulate(st.begin(), st.end(), 0);
        return sum > 0 ? sum : mx_non_pos;
    }
};