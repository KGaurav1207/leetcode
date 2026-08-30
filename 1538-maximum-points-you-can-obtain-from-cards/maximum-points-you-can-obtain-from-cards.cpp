class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int n = p.size();

        vector<int> prefix(k + 1, 0);
        vector<int> suffix(k + 1, 0);

        
        for (int i = 1; i <= k; i++) {
            prefix[i] = prefix[i - 1] + p[i - 1];
        }

        
        for (int i = 1; i <= k; i++) {
            suffix[i] = suffix[i - 1] + p[n - i];
        }

        int ans = 0;

        
        for (int i = 0; i <= k; i++) {
            ans = max(ans, prefix[i] + suffix[k - i]);
        }

        return ans;
    }
};