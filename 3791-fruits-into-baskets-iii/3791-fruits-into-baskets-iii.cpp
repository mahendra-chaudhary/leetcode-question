class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& baskets) {
        n = baskets.size();
        tree.resize(4 * n);
        build(baskets, 1, 0, n - 1);
    }

    void build(const vector<int>& baskets, int node, int l, int r) {
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(baskets, 2 * node, l, mid);
        build(baskets, 2 * node + 1, mid + 1, r);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // Returns index of leftmost basket >= val and marks it used
    int queryAndUse(int node, int l, int r, int val) {
        if (tree[node] < val) return -1;

        if (l == r) {
            tree[node] = -1; // Mark as used
            return l;
        }

        int mid = (l + r) / 2;
        int res = -1;

        if (tree[2 * node] >= val) {
            res = queryAndUse(2 * node, l, mid, val);
        } else {
            res = queryAndUse(2 * node + 1, mid + 1, r, val);
        }

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        return res;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree segTree(baskets);

        int unplaced = 0;
        for (int fruit : fruits) {
            int idx = segTree.queryAndUse(1, 0, n - 1, fruit);
            if (idx == -1) {
                ++unplaced;
            }
        }
        return unplaced;
    }
};
