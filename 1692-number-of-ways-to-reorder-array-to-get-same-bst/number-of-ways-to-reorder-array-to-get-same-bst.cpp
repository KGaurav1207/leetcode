class Solution {
    static constexpr long long MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long b, long long e) {
        long long r = 1;
        b %= MOD;
        while (e > 0) {
            if (e & 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    long long combination(int nl, int nr) {
        return fact[nl + nr] * invFact[nl] % MOD * invFact[nr] % MOD;
    }

    long long ways(const vector<int>& arr) {
        if (arr.size() <= 2) return 1;

        int root = arr[0];
        vector<int> left, right;
        for (int num : arr) {
            if (num < root) left.push_back(num);
            else if (num > root) right.push_back(num);
        }

        return ways(left) * ways(right) % MOD
               * combination(left.size(), right.size()) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact.assign(n + 1, 1);
        invFact[n] = power(fact[n], MOD - 2);   // Fermat's little theorem
        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return (ways(nums) - 1 + MOD) % MOD;
    }
};