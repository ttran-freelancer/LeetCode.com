// https://leetcode.com/problems/find-the-most-common-response/description

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> mp;
        for (auto response : responses) {
            set<string> st;
            for (auto r : response) {
                if (st.find(r) == st.end()) {
                    mp[r]++;
                    st.insert(r);
                }
            }
        }
        
        int mx = 0;
        vector<string> result;
        for (auto m : mp) {
            if (m.second >= mx) {
                if (m.second > mx) {
                    mx = m.second;
                    result.clear();
                }
                result.push_back(m.first);
            }
        }
        
        sort(result.begin(), result.end());
        return result[0];
    }
};