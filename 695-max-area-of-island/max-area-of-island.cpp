class Solution {

    int fun(vector<vector<int>>&grid, vector<vector<int>>&vis, int i, int j, int n, int m){
        int l[] = {0,0,1,-1};
        int k[] = {1,-1,0,0};
        int ans = 0;

        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            ans++;
           // bool flag = false;

            for(int i = 0; i<4; i++){
                int nx = x + l[i];
                int ny = y + k[i];

                if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || grid[nx][ny] == 0) continue;
                if(grid[nx][ny] == 1){
                    //  if(nx == 0 || ny == 0 || nx == n || ny == m){
                    //     ans = 0; 
                    //     flag = true;
                    //     return ans;
                    //     break;
                    //  }
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            } 
            // if(flag){
            //     break;
            // }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        int res = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j]) continue;
                else if(!vis[i][j] && grid[i][j] == 1){
                    res = max(res,fun(grid, vis, i, j, n, m));
                }
            }
        }

        return res;
    }
};