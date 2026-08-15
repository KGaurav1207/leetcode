class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 1) mat[i][j] += mat[i-1][j];
            }
        }
         for(int i = 0; i<n; i++){
            sort(mat[i].begin(), mat[i].end(),greater());
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0) break;
                ans = max(ans, mat[i][j]*(j+1));
            }
        }

        return ans;

    }
};