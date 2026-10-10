class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int mx = 0;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, d[i]);
        }

        vector<long long> cnt(mx + 1, 0);
        for (int x : d) cnt[x]++;

        for (int i = mx; i >= 1 && k > 0; i--) {
            long long moie = min(k, cnt[i]);  
            cnt[i] -= moie;
            cnt[i - 1] += moie;
            k -= moie;
        }

        long long ans = 0;
        for (long long i = 0; i <= mx; i++) ans += cnt[i] * i * i;
        return ans;
    }
};