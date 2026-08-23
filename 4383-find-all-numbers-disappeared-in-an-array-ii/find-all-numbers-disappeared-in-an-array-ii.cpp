class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        int st = lower, i = 0;

        if(n == 0 || nums[0] > upper || nums[n-1]<lower) return {{lower, upper}};
        
        for(; i<n; i++){
            if(nums[i] > upper) break;
            if(nums[i]<st){
                continue;
            }
            if(nums[i] == st){
                st++;
            }
            else if(nums[i]>st){
            ans.push_back({st, nums[i]-1});
            st = nums[i]+1;
            }
        }
        
        if(st<=upper) ans.push_back({st,upper});
        

        return ans;
    }

};