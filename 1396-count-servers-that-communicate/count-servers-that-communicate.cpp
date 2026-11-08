class Solution {
    vector<vector<bool>>find;

    void check(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        int ri = i-1, ci = j-1, rj = i+1, cj = j+1;
        while(ri>=0){
            if(grid[ri][j] == 1){
                find[ri][j] = 1;
                ans ++;
            }
            ri--;
        }
        while(rj<n){
            if(grid[rj][j] == 1){
                find[rj][j] = 1;
                ans ++;
            }
            rj++;
        }
        while(ci>=0){
            if(grid[i][ci] == 1){
                find[i][ci] = 1;
                ans ++;
            }
            ci--;
        }
        while(cj<m){
            if(grid[i][cj] == 1){
                find[i][cj] = 1;
                ans ++;
            }
            cj++;
        }
        if(ans >0) find[i][j] = 1;
    }

public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        find.assign(n, vector<bool>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && find[i][j] == 0){
                    check(grid, i, j);
                    
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(find[i][j] == 1){
                    ans++;
                    
                }
            }
        }

        return ans;

    }
};