class Solution {

    void fun(vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j, int n, int m){
        int l[] = {0,0,1,-1};
        int k[] = {1,-1,0,0};

        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int nx = x + l[i];
                int ny = y + k[i];

                if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || grid[nx][ny] - '0' == 0) continue;
                if(grid[nx][ny] - '0' == 1){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            } 
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]) continue;
                else if(!vis[i][j] && grid[i][j] - '0' == 1){
                    ans++;
                    fun(grid, vis, i, j, n, m);
                }
            }
        }

        return ans;

    }
};