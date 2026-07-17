/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<vector<int>>temp = mat;

        int r = 0;
        int n = mat.size(), m = mat[0].size();
        int mx = -1;
        for(int i = 0;i<n; i++){
            sort(temp[i].begin(), temp[i].end());
            if(temp[i][m-1] > mx){
                mx = temp[i][m-1];
                r = i;
            }
        }

        for(int j=0; j<m; j++){
            if(mat[r][j] == mx) return {r,j};
        }

        return {-1,-1};
    }
};
// @lc code=end

