class Solution {
    vector<int>r = {0,0,-1,1};
    vector<int>c = {1,-1,0,0};
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i<0 || i >= n || j<0 || j >= m) return 0;
        if(grid[i][j]!=0) return 1;
        grid[i][j] = -1;
        int res = 1;
        for(int k = 0; k<4; k++){
            //if(grid[i+r[k]][j+c[k]] == 0){
                res &= solve(grid, n,m, i+r[k], j+c[k]);
            //}
        }

        return res;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0){
                    ans += solve(grid, n,m,i,j);
                }
            }
        }

        return ans;
    }
};