class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<int>> dist(n,vector<int>(k + 1, INT_MAX));
        vector<vector<pair<int,int>>> g(n);
        for(auto& e : edges)
            g[e[0]].push_back(make_pair(e[1],e[2]));
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>>pq;
        dist[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d, u, c] = pq.top();
            pq.pop();
            if(d > dist[u][c])
                continue;
            for(auto& [v, wt] : g[u]){
                int nc = 1;
                if(labels[u] == labels[v])
                    nc = c + 1;
                if(nc > k)
                    continue;
                int nd = wt + d;
                if(nd < dist[v][nc]){
                    dist[v][nc] = nd;
                    pq.push({nd,v,nc});
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0 ; i <= k ; i++)
            res = min(res, dist[n - 1][i]);
        if(res == INT_MAX)
            return -1;
        return res;
    }
};