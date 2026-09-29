class Solution {
    bool fun(vector<vector<char>>& g, int n, int m,
             int x, int y, int open,
             vector<vector<vector<int>>>& dp) {
        if(x>=n || y>=m) return false;

        if(g[x][y] == '(') open++;
        else open--;

        if(open<0) return false;
        
        int remain = (n-x-1) + (m-y-1);
        if(open > remain) return false;

        if(dp[x][y][open]!=-1) return dp[x][y][open];

        if(x == n-1 && y == m-1) return dp[x][y][open] = (open == 0);

        if(fun(g,n,m,x+1,y,open,dp)) return dp[x][y][open]=true;
        if(fun(g,n,m,x,y+1, open,dp)) return dp[x][y][open]=true;

        return dp[x][y][open] = false;

       
    }

public:
    bool hasValidPath(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();

       
       if((m+n-1)%2 != 0) return false;

       if(g[0][0] == ')') return false;

       if(g[n-1][m-1] == '(') return false;

       vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m+n,-1)));

        return fun(g, n, m, 0, 0, 0, dp);
    }
};