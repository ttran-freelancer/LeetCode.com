// https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        using PII = pair<int, int>;
        map<PII, int> weight;
        vector<int> cost(n, INT_MIN);
        vector<vector<int>> E(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (weight.find({u, v}) == weight.end() || weight[{u, v}] > w) {
                 weight[{u, v}] = w;   
            }
            
            E[v].push_back(u);
        }

        auto solve = [&]() -> int {
            queue<int> q({0});
            while (!q.empty()) {
                auto v = q.front();
                q.pop();
                for (auto u : E[v]) {
                    int c = max(cost[v], weight[{u, v}]);
                    if (cost[u] == INT_MIN || cost[u] > c) {
                        cost[u] = c;
                        q.push(u);
                    }
                }
            }

            int mx = INT_MIN;
            for (int i = n - 1; i > 0; i--) {
                if (cost[i] == INT_MIN) {
                    return -1;
                }
                mx = max(mx, cost[i]);
            }

            return mx;
        };

        return solve();
    }
};