class Solution {
    int fun(vector<int>& nums){
        int n = nums.size();
        int ans = 1, mx = 1;

        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){
                mx++;
                ans = max(mx,ans);
                continue;
            }
            mx = 1;
        }
        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans1 = fun(nums);
        reverse(nums.begin(), nums.end());
        int ans2 = fun(nums);

        return max(ans1, ans2);

    }
};