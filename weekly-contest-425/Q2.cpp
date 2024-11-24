// https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/description/
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> mp;
        int step = s.size() / k;
        
        for (int i = 0; i < s.size(); i += step) {
            string chunk = s.substr(i, step);
            mp[chunk]++;
        }

        for (int i = 0; i < t.size(); i += step) {
            string chunk = t.substr(i, step);
            if (--mp[chunk] < 0) {
                return false;
            }
        }

        return true;
    }
};