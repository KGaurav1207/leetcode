class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
       vector<int> ans(n+1, INT_MAX);
        ans[0] =  0;
       for(int i = 1; i<=n; i++){
        int prevcost =  costs[i-1];
        for(int j = max(0,i-3); j<i; j++){
            ans[i] = min(ans[i], prevcost + ans[j] + (i-j)*(i-j));
        }
       } 

       return ans[n];
    }
};