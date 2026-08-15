class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));

        int mx = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0) mat[i][j] = 1;
                    else mat[i][j] = 1 + min({mat[i-1][j], mat[i][j-1], mat[i-1][j-1]});
                }
                mx = max(mat[i][j], mx);
             }
        }

        return mx*mx;
    }
};