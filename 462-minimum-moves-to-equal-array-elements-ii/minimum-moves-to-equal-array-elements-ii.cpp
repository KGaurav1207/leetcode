class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 1) return 0;

        int med = n%2 == 0 ? nums[n/2]:(nums[(n-1)/2] + nums[n/2])/2;

        int ans = 0;

        for(auto & y: nums){
            ans += abs(med - y);
        }

        return ans;
    }
};