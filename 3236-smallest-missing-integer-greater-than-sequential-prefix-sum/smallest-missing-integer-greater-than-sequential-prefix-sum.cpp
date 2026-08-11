class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();

        int sum = nums[0], cnt = 1, l = 1;
        unordered_map<int,int>mp;
      
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }

        for(int i = 1; i<n; i++){
            
            if(nums[i] == nums[i-1] + 1){
                ans += nums[i];
            }
            else {
                break;
            }
        }

        while(1){
            if(mp.count(ans) == 0) return ans;
            ans++;
        }

        return 0;
    }
};