class Solution {
public:
    vector<int> nums;
    vector<vector<int>> tree;
    vector<int> xorSubtree;
    vector<int> inTime, outTime;
    int timer = 0;

    void dfs(int u, int parent) {
        xorSubtree[u] = nums[u];
        inTime[u] = timer++;
        for (int v : tree[u]) {
            if (v == parent) continue;
            dfs(v, u);
            xorSubtree[u] ^= xorSubtree[v];
        }
        outTime[u] = timer++;
    }

    bool isAncestor(int u, int v) {
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }

    int minimumScore(vector<int>& nums_, vector<vector<int>>& edges) {
        nums = nums_;
        int n = nums.size();
        tree.resize(n);
        xorSubtree.assign(n, 0);
        inTime.resize(n);
        outTime.resize(n);

        for (auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        int ans = INT_MAX;
        int totalXor = xorSubtree[0];

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;
                if (isAncestor(a, b)) {
                    int xor1 = xorSubtree[b];
                    int xor2 = xorSubtree[a] ^ xorSubtree[b];
                    int xor3 = totalXor ^ xorSubtree[a];
                    ans = min(ans, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                } else if (isAncestor(b, a)) {
                    int xor1 = xorSubtree[a];
                    int xor2 = xorSubtree[b] ^ xorSubtree[a];
                    int xor3 = totalXor ^ xorSubtree[b];
                    ans = min(ans, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                } else {
                    int xor1 = xorSubtree[a];
                    int xor2 = xorSubtree[b];
                    int xor3 = totalXor ^ xor1 ^ xor2;
                    ans = min(ans, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
                }
            }
        }

        return ans;
    }
};
