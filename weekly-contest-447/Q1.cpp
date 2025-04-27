// https://leetcode.com/contest/weekly-contest-447/problems/count-covered-buildings/description

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> hmin(n + 1, 1e5 + 1);
        vector<int> hmax(n + 1, -1);
        vector<int> vmin(n + 1, 1e5 + 1);
        vector<int> vmax(n + 1, -1);
        
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            hmin[x] = min(hmin[x], y);
            hmax[x] = max(hmax[x], y);
            vmin[y] = min(vmin[y], x);
            vmax[y] = max(vmax[y], x);
        }

        int ans = 0;
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0];
            int y = buildings[i][1];
            if (y > hmin[x] && y < hmax[x] && x > vmin[y] && x < vmax[y]) {
                ans++;
            }
        }

        return ans;
    }
};