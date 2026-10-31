class Solution {
    
    const int MOD = 1e9 + 7;

    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int prev, int i, int j){
        if(i == grid.size() || j == grid[0].size()) return 0;
        if(i == grid.size()-1 && j == grid[0].size()-1) return 1;

        if(dp[i][j][prev+1] != -1) return dp[i][j][prev+1];

        int right = 0, down = 0;
        if(grid[i][j] == 1){
            if(prev == 0){
                right = solve(grid, dp, 1, i+1, j);   //prev == 0 --> right so nextprev = 1(down)
            }
            else down = solve(grid, dp, 0, i, j+1);        // prev == 1 --> down so nextprev = 0(right)
        }
        else {
            right = solve(grid, dp, 1, i+1, j);
            down = solve(grid, dp, 0, i, j+1);
        }

        return dp[i][j][prev+1] = (right + down)%MOD;

    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));

        int ans = solve(grid, dp, 0, 0, 0);

        return ans;
    }
};