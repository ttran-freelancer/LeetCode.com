// https://leetcode.com/problems/unit-conversion-i/description

class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        int mod = 1e9 + 7;
        
        map<int, vector<int>> mp; 
        for (int i = 0; i < n - 1; i++) {
            auto c = conversions[i];
            mp[c[0]].push_back(i);
        }

        queue<int> q{{0}};
        vector<int> ans(n);
        ans[0] = 1;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (int i = 0; i < mp[u].size(); i++) {
                int v = mp[u][i];   
                auto c = conversions[v];
                ans[c[1]] = (long long)ans[c[0]]*c[2] % mod;
                q.push(c[1]);
            }
        }
            
        return ans;
    }
};