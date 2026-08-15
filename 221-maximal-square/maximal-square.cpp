class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0){
                    mat[i][j] = matrix[i][j] - '0';
                }
                else{
                   mat[i][j] = matrix[i][j] - '0';
                   if(mat[i][j] == 1) mat[i][j] += mat[i-1][j];
                }
            }
        }

        int ans = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]!=0){
                    int cnt = 1;
                    int c = j;
                    int curr = mat[i][c];
                    while(c<m && mat[i][c] > 0){
                        curr = min(curr, mat[i][c]);
                        //ans = max(ans, curr);
                        int size = min(curr, cnt);
                        ans =max(ans, size*size);
                        cnt++;
                        c++;
                    }
                }
            }
        }

        return ans;
    }
};