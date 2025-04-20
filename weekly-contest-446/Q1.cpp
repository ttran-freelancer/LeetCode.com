// https://leetcode.com/contest/weekly-contest-446/problems/calculate-score-after-performing-instructions/description

class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> visited(n, false);
        long long ans = 0LL;
        

        for (int i = 0; i >= 0 && i < n;) {
            if (visited[i]) break;
            visited[i] = true;
            if (instructions[i] == "add") {
                ans += values[i];
                i++;
            } else {
                i += values[i];
            }
        }

        return ans;
    }
};