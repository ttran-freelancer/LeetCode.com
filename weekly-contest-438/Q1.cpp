// https://leetcode.com/contest/weekly-contest-438/problems/check-if-digits-are-equal-in-string-after-operations-i/

class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                s[j] = (s[j] - '0' + s[j + 1] - '0') % 10 + '0';
            }
        }

        return s[0] == s[1];
    }
};