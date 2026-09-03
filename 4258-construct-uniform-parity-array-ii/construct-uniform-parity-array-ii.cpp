class Solution {
public:
    bool uniformArray(vector<int>& nums) {
       int n = nums.size();
       int mn = INT_MAX, idx = -1;
       for(int i = 0; i < n; i++){
          if(nums[i]<mn){
             mn = nums[i];
             idx = i;
            }
       }

       if(!(mn & 1)){
            for(int i = 0 ; i<n; i++){
                if(nums[i]&1) return false;
            }
       } 
      
      return true;
    }
};