class Solution {
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j, int x, vector<vector<vector<int>>>&dp){
        if(i>=n || j>= m) return INT_MAX;

        if(dp[i][j][x] != -1) return dp[i][j][x];

        int nx = x^grid[i][j];

        if(i == n-1 && j == m-1) return dp[i][j][x] = nx;

        int a = solve(grid, n, m, i, j+1, nx, dp);
        int b =  solve(grid, n, m, i+1, j, nx, dp);


        return dp[i][j][x] = min(a,b);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(1024, -1)));
        
        

        return solve(grid, n, m, 0, 0, 0, dp);
    }
};