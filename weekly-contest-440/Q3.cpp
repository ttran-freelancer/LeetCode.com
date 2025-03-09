// https://leetcode.com/problems/fruits-into-baskets-iii

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;

        vector<int> mx(n + 1);
        for (int i = 0; i < n; i++) {
            mx[i+1] = max(mx[i], baskets[i]);
        }

        for (int i = 0; i < n; i++) {
            if (fruits[i] > mx[n]) {
                ans++;
                continue;
            }
            int idx = lower_bound(mx.begin(), mx.end(), fruits[i]) - mx.begin();
            if (idx == n + 1) {
                ans++;
                continue;
            }

            int midx = mx[idx];
            int bidx = baskets[idx-1];
            baskets[idx-1] = 0;
            mx[idx] = mx[idx - 1];
            for (int j = idx; j < n && baskets[j] < bidx; j++) {
                if (mx[j+1] == midx) {
                    mx[j+1] = max(mx[j], baskets[j]);
                }
            }
        }

        return ans;
    }
};
