class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        unordered_map<int,int>mp;
        int ans = 1;

        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
               ans = max(ans, j-i);
               mp[nums[i]]--;
               i++;
            }
            j++;
        }
        ans = max(ans, j-i);

        return ans;
    }
};