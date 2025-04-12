// https://leetcode.com/contest/biweekly-contest-154/problems/number-of-unique-xor-triplets-ii/description

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }

        unordered_set<int> st2;
        for (auto it = st.begin(); it != st.end(); it++) {
            for (auto it2 = next(it); it2 != st.end(); it2++) {
                st2.insert((*it)^(*it2));
            }
        }

        unordered_set<int> ans(st.begin(), st.end());
        for (auto it = st.begin(); it != st.end(); it++) {
            for (auto it2 = st2.begin(); it2 != st2.end(); it2++) {
                ans.insert((*it)^(*it2));
            }
        }

        return ans.size();
    }
};