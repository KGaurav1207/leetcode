class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), depth(n, 0), base(n, 0), it(n, 0);

        // iterative DFS: Euler tour, depth, parents, root->node prefix masks
        int timer = 0;
        vector<int> st = {0};
        tin[0] = timer++;
        base[0] = 1 << (s[0] - 'a');
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)g[u].size()) {
                int v = g[u][it[u]++];
                if (v == up[0][u]) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int j = 1; j < LOG; j++)
            for (int v = 0; v < n; v++)
                up[j][v] = up[j - 1][up[j - 1][v]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (diff >> j & 1) u = up[j][u];
            if (u == v) return u;
            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }
            return up[0][u];
        };

        // Fenwick tree over XOR: range-xor update, point query
        vector<int> bit(n + 1, 0);
        auto upd = [&](int pos, int val) {
            for (int i = pos + 1; i <= n; i += i & -i) bit[i] ^= val;
        };
        auto qry = [&](int pos) {
            int r = 0;
            for (int i = pos + 1; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto prefix = [&](int x) { return base[x] ^ qry(tin[x]); };

        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int d = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (d) {
                    upd(tin[u], d);
                    if (tout[u] + 1 < n) upd(tout[u] + 1, d);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = prefix(u) ^ prefix(v) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};