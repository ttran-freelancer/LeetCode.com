// https://leetcode.com/problems/choose-k-elements-with-maximum-sum/description

class Solution {
public:
    struct Item {
        int id;
        int val;
        Item(int i, int v) : id(i), val(v) {}
    };

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0L);
        vector<Item> vi;

        for (int i = 0; i < n; i++) {
            vi.push_back(Item(i, nums1[i]));
        }

        auto cmp = [](const Item& a, const Item& b) {
            return a.val < b.val || (a.val == b.val && a.id < b.id);
        };
        sort(vi.begin(), vi.end(), cmp);

        long long sum = 0L;
        int lval = 0;
        vector<int> lvec;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            int id = vi[i].id;
            int val = vi[i].val;

            if (val > lval) {
                for (auto l : lvec) {
                    pq.push(l);
                    sum += l;
                }
                lvec.clear();
                while (pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
                lval = val;
            }

            ans[id] = sum;
            lvec.push_back(nums2[id]);
        }

        return ans;
    }
};