class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        int ans = mx-mn, val = mx-mn;
        sort(nums.begin(), nums.end());

        for(int i = nums.size() - 2; i>=0; i--){
            ans  += (nums[i] + val) - mx;
        }

        return ans;
        

    }
};