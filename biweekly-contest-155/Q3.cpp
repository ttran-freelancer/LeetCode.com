// https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description

class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size();
        int n = grid[0].size();
        int k = pattern.size();

        auto id2h = [&](int idx) -> pair<int, int> {
            int x = idx / n;
            int y = idx % n;
            return {x, y};
        };

        auto h2id = [&](const pair<int, int>& p) -> int {
            return p.first*n + p.second;
        };
        
        auto id2v = [&](int idx) -> pair<int, int> {
            int x = idx % m;
            int y = idx / m;
            return {x, y}; 
        };

        auto v2id = [&](const pair<int, int>& p) -> int {
            return p.first + p.second*m;
        };
        
        string h(m*n, ' '), v(m*n, ' ');
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                h[h2id({i, j})]= grid[i][j];
                v[v2id({i, j})]= grid[i][j];
            }
        }
        
        vector<int> rh, rv;        
        int idx = -1;
        do {
            idx = h.find(pattern, idx + 1);
            
            if (idx == string::npos) break;
            rh.push_back(idx);
        } while (1);
        idx = -1;
        do {
            idx = v.find(pattern, idx + 1);
            if (idx == string::npos) break;
            rv.push_back(idx);
        } while (1);

        map<pair<int, int>, int> mp;
        for (int i = 0, j = 0; i < rh.size(); i++) {
            j = max(j, rh[i]);
            for (; j < rh[i] + k; j++) {
                auto p = id2h(j);
                mp[p] = 1;
            }
        }
        for (int i = 0, j = 0; i < rv.size(); i++) {
            j = max(j, rv[i]);
            for (; j < rv[i] + k; j++) {
                auto p = id2v(j);
                if (mp.find(p) != mp.end()) {
                    mp[p] = 2;
                }
            }
        }
        
        int ans = 0;
        for (auto m : mp) {
            if (m.second == 2) {
                ans++;
            }
        }
        
        return ans;
    }
};