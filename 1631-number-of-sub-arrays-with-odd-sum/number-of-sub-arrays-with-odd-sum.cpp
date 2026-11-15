class Solution {
public:
   int numOfSubarrays(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int odd = 0, even = 1, total_odd = 0, prefix_sum = 0;
    for (int num : arr) {
        prefix_sum += num;
        if (prefix_sum % 2 == 1) {
            total_odd = (total_odd + even) % MOD;
            odd++;
        } else {
            total_odd = (total_odd + odd) % MOD;
            even++;
        }
    }
    return total_odd;

}
};