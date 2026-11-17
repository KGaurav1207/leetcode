class Solution {
public:
    const int INF = 1e9;

    
    int semi_changes(const string &s, int l, int r) {
        int len = r - l + 1;
        if (len < 2) return INF;
        int best = INF;
        for (int d = 1; d < len; ++d) {
            if (len % d) continue;
            int changes = 0;
            for (int g = 0; g < d; ++g) {
                int a = l + g;
                int b = l + g + (len / d - 1) * d;
                while (a < b) {
                    if (s[a] != s[b]) changes++;
                    a += d;
                    b -= d;
                }
            }
            best = min(best, changes);
        }
        return best;
    }

    int minimumChanges(string s, int k) {
        int n = s.length();

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int l = 0; l < n; ++l)
            for (int r = l + 1; r < n; ++r)
                cost[l][r] = semi_changes(s, l, r);

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; ++j) {
            for (int i = 2 * j; i <= n; ++i) {
                for (int m = 2 * (j - 1); m <= i - 2; ++m) {
                    if (dp[m][j - 1] >= INF) continue;
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};