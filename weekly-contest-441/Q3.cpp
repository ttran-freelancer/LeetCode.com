// https://leetcode.com/contest/weekly-contest-441/problems/zero-array-transformation-iv/description

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m = nums.size();
        int n = queries.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (nums[i] == 0) continue;
            
            vector<bool>L(1001, false);
            int current = -1;
            L[nums[i]] = true;
            for (int j = 0; j < n; j++) {
                if (i < queries[j][0] || i > queries[j][1]) continue;
                
                if (L[queries[j][2]]) {
                    current = j + 1;
                    break;
                }
                
                for (int k = queries[j][2] + 1; k <= 1000; k++) {
                    if (L[k]) {
                        L[k - queries[j][2]] = true;
                    }
                }
            }
            
            if (current == -1) {
                return -1;
            } 
            ans = max(ans, current);
        }
        
        return ans;
    }
};