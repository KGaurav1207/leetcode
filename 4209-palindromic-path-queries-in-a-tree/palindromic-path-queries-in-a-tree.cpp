class Solution {
    vector<string> getWords(const string& s) {
        vector<string> ans;
        string word;
        for(auto c : s) {
            if(c==' ' && word.length()) {
                ans.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        if(word.length()) ans.push_back(word);
        return ans;
    }
    
    int stoi(const string& s) {
        int n = 0;
        for(auto c : s) {
            int d = c - '0';
            n = n*10 + d;
        }        
        return n;
    }

    void dfs(int i, int parent, vector<int> adj[], vector<int>& in, vector<int>& out, int& time) {
        in[i] = time;

        for(auto adjN:adj[i]) {
            if(adjN != parent)
                dfs(adjN, i, adj, in, out, ++time);
        }

        out[i] = ++time;
        return;
    }

    void buildLCA(int i, int parent, vector<int> adj[], vector<int>& depth, vector<vector<int>>& up) {
        // 1. Set immediate parent
        up[i][0] = parent;
        
        // 2. Set depth
        if (parent != -1) {
            depth[i] = depth[parent] + 1;
        }
        
        // 3. Build the highway jumps for this node
        for (int j = 1; j < 20; j++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[ up[i][j - 1] ][j - 1];
            } else {
                up[i][j] = -1;
            }
        }

        // 4. Traverse children
        for (auto adjN : adj[i]) {
            if (adjN != parent) {
                buildLCA(adjN, i, adj, depth, up);
            }
        }
    }

    void build(int i, int low, int high, vector<int>& seg, vector<int>& leaf) {
        if(low == high) {
            seg[i] = leaf[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2*i+1, low, mid, seg, leaf);
        build(2*i+2, mid+1, high, seg, leaf);

        seg[i] = seg[2*i+1] ^ seg[2*i+2];
        return;
    }

    void update(int i, int low, int high, vector<int>& seg, int node, int val) {
        if(low == high) {
            seg[i] = val;
            return;
        }

        int mid = (low + high) / 2;
        if(low <= node && node <= mid)
            update(2*i+1, low, mid, seg, node, val);
        else
            update(2*i+2, mid+1, high, seg, node, val);

        seg[i] = seg[2*i+1] ^ seg[2*i+2];
        return;
    }

    int query(int i, int low, int high, int l, int r, vector<int>& seg) {
        if(l <= low && high <= r) return seg[i];
        if(r < low || high < l) return 0;

        int mid = (low + high) / 2;
        int left = query(2*i+1, low, mid, l, r, seg);
        int right = query(2*i+2, mid+1, high, l, r, seg);

        return left ^ right;
    }

    // O(log N) LCA based on BINARY LIFTING
    int getLCAidx(int u, int v, const vector<int>& depth, const vector<vector<int>>& up) {
        // 1. Force u to be the deeper node
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        
        // 2. Jump u up until it matches v's depth
        for (int j = 19; j >= 0; j--) {
            if (up[u][j] != -1 && depth[up[u][j]] >= depth[v]) {
                u = up[u][j];
            }
        }
        
        // If they met, we found the LCA!
        if (u == v) {
            return u;
        }
        
        // 3. Jump both up together just below the LCA
        for (int j = 19; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        
        // The LCA is the immediate parent of where they stopped
        return up[u][0];
    }

    bool palindromePossible(const int& n) {
        if(n & (n-1)) 
            return false;
        return true;
    }
    
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<int> adj[n];
        for(auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> in(n, -1), out(n, -1); 
        int time = 0;
        dfs(0, -1, adj, in, out, time);

        // BINARY LIFTING
        vector<int> depth(n, 0);
        vector<vector<int>> up(n, vector<int>(20, -1));
        buildLCA(0, -1, adj, depth, up);

        vector<int> leaf(2*n, 0);
        for(int i=0; i<n; i++) {
            int mask = 1 << (s[i]-'a');
            leaf[in[i]] = mask;
            leaf[out[i]] = mask;
        }
        vector<int> seg(4*2*n+1, 0); 
        build(0, 0, 2*n-1, seg, leaf);

        vector<bool> ans;

        for(auto it : queries) {
            vector<string> words = getWords(it);

            if(words[0] == "update") {
                int u = stoi(words[1]);
                char c = words[2][0];
                int mask = 1 << (c-'a');
                update(0, 0, 2*n-1, seg, in[u], mask);
                update(0, 0, 2*n-1, seg, out[u], mask);
                s[u] = c;
            } else {
                int u = stoi(words[1]);
                int v = stoi(words[2]);

                // int lcaIdx = getLCAidx(0, -1, u, v, adj); // using O(N) binary tree
                int lcaIdx = getLCAidx(u, v, depth, up); // using O(log N) BINARY LIFTING

                int rootToU = query(0, 0, 2*n-1, 0, in[u], seg);
                int rootToV = query(0, 0, 2*n-1, 0, in[v], seg);
                // int lcaMask = query(0, 0, 2*n-1, in[lcaIdx], in[lcaIdx], seg);
                int lcaMask = 1 << (s[lcaIdx]-'a');

                bool pos = palindromePossible(rootToU ^ rootToV ^ lcaMask);
                ans.push_back(pos);
            }
        }

        return ans;
    }
};