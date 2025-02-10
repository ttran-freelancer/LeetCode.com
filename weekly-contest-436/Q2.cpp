// https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int m = groups.size();
        int n = elements.size();

        map<int, int> smallest;
        vector<int> result(1e5 + 1, -1);

        for (int i = n - 1; i >= 0; i--) {
            smallest[elements[i]] = i;
        }

        for (auto m : smallest) {            
            for (int j = m.first; j <= 1e5; j += m.first) {
                result[j] = result[j] != -1 ? min(result[j], m.second) : m.second;
            }   
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = result[groups[i]];
        }

        return ans;
    }
};