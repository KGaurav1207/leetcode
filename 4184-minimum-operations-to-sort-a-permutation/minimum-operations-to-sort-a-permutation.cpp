class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int z = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool right = true;
        for (int i = 0; i < n; i++) {
            if (nums[(z + i) % n] != i) right = false;
        }

        bool left = true;
        for (int i = 0; i < n; i++) {
            if (nums[(z - i + n) % n] != i) left = false;
        }

        int ans = INT_MAX;

        if (right) ans = min({ans, z, n - z + 2});
        if (left)  ans = min({ans, z + 2, n - z});

        return ans == INT_MAX ? -1 : ans;
    }
};