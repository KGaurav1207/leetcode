class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       int n = nums.size();

       int mx = max_element(nums.begin(), nums.end()) - nums.begin() + 1;
       int mn = min_element(nums.begin(), nums.end()) - nums.begin() + 1;


       int ans = min({max(mx,mn) , n - min(mx,mn) + 1, min(mn, n - mn) + min(mx, n - mx) + 1});

       return ans;


    }
};