// https://leetcode.com/contest/weekly-contest-441/problems/closest-equal-element-queries/description

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int val = nums[queries[i]];
            if (mp[val].size() <= 1) {
                ans[i] = -1;
                continue;
            }

            int m = mp[val].size();
            int pos = lower_bound(mp[val].begin(), mp[val].end(), queries[i]) -
                        mp[val].begin();
            int left = mp[val][(pos + m - 1) % m];
            int right = mp[val][(pos + 1) % m];
            ans[i] = min({abs(queries[i] - left),
                            (int)nums.size() - abs(queries[i] - left),
                            abs(queries[i] - right),
                            (int)nums.size() - abs(queries[i] - right)});
        }

        return ans;
    }
};