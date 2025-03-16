// https://leetcode.com/problems/unique-3-digit-even-numbers/description

class Solution {
public:
    void backtracking(vector<int> digits, int start, vector<int>& current, set<int>& st) {
        if (start == 3) {
            st.insert(100*current[0] + 10*current[1] + current[2]);
            return;
        }

        if (digits.empty()) {
            return;
        }

        for (int i = 0; i < digits.size(); i++) {
            if (start == 0 && digits[i] == 0) continue;
            if (start == 2 && digits[i] % 2 != 0) continue;

            current[start] = digits[i];
            auto tmp = digits;
            tmp.erase(tmp.begin() + i);
            backtracking(tmp, start + 1, current, st);
        }
        
        auto tmp = digits;
        tmp.erase(tmp.begin());
        backtracking(tmp, start, current, st);
    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> st;
        vector<int> current(3, 0);
        backtracking(digits, 0, current, st);
        return st.size();
    }
};