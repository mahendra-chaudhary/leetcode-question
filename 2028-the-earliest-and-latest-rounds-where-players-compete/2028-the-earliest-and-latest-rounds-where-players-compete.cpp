class Solution {
public:
    unordered_map<string, pair<int, int>> memo;

    pair<int, int> dfs(vector<int>& players, int f, int s, int round) {
        int n = players.size();
        for (int i = 0; i < n / 2; ++i) {
            int a = players[i], b = players[n - 1 - i];
            if ((a == f && b == s) || (a == s && b == f))
                return {round, round};
        }

        string key = encode(players);
        if (memo.count(key)) return memo[key];

        vector<vector<int>> nextStates;
        generate(players, f, s, 0, n - 1, {}, nextStates);

        int mn = INT_MAX, mx = INT_MIN;
        for (auto& next : nextStates) {
            sort(next.begin(), next.end());
            auto res = dfs(next, f, s, round + 1);
            mn = min(mn, res.first);
            mx = max(mx, res.second);
        }
        return memo[key] = {mn, mx};
    }

    void generate(vector<int>& players, int f, int s, int l, int r, vector<int> cur, vector<vector<int>>& nexts) {
        if (l > r) {
            nexts.push_back(cur);
            return;
        }
        if (l == r) {
            cur.push_back(players[l]);
            nexts.push_back(cur);
            return;
        }

        int a = players[l], b = players[r];
        if ((a == f && b == s) || (a == s && b == f)) return;

        if (a == f || a == s) {
            cur.push_back(a);
            generate(players, f, s, l + 1, r - 1, cur, nexts);
            cur.pop_back();
        }
        else if (b == f || b == s) {
            cur.push_back(b);
            generate(players, f, s, l + 1, r - 1, cur, nexts);
            cur.pop_back();
        }
        else {
            cur.push_back(a);
            generate(players, f, s, l + 1, r - 1, cur, nexts);
            cur.pop_back();
            cur.push_back(b);
            generate(players, f, s, l + 1, r - 1, cur, nexts);
            cur.pop_back();
        }
    }

    string encode(const vector<int>& v) {
        string s;
        for (int x : v) {
            s += to_string(x) + ",";
        }
        return s;
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> players(n);
        iota(players.begin(), players.end(), 1);
        memo.clear();
        auto [mn, mx] = dfs(players, firstPlayer, secondPlayer, 1);
        return {mn, mx};
    }
};
