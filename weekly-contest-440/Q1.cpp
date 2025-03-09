// https://leetcode.com/problems/fruits-into-baskets-ii/description/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> available(n, true);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= fruits[i] && available[j]) {
                    available[j] = false;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                ans++;
            }
        }

        return ans;
    }
};