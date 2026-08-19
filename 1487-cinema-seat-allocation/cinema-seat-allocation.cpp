class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        sort(res.begin(), res.end());
        int m = res.size();
        int j = 0, ans = 0;
        int cnt = 0;
        while (j < m) {
            vector<int> v(11, 0);
            int r = res[j][0];
            while (j < m && res[j][0] == r) {
                v[res[j][1]]++;
                j++;
            }
            cnt++;
            if (v[2] == 0 && v[3] == 0) {
                if (v[4] == 0 && v[5] == 0) {
                    ans++;
                }
                if (v[6] == 0 && v[7] == 0 &&
                    v[8] == 0 && v[9] == 0) {
                    ans++;
                }
            }
            else {
                if (v[4] == 0 && v[5] == 0 &&
                    v[6] == 0 && v[7] == 0 || v[6] == 0 && v[7] == 0 &&
                    v[8] == 0 && v[9] == 0) {
                    ans++;
                }
            }
        }
        ans += (n - cnt) * 2;
        return ans;
    }
};