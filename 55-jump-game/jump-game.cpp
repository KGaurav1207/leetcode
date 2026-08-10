class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int t = n-1;
      int c = n-2;
      if(nums[0] == 0 && n>1) return false;

      if(c<0) return true;
      int i = n-2;

      for(; i>=0; i--){
        
        if(nums[i] + i >= t) {
            t = i;
            c = i-1;
        }
      }
      //if(nums[i] ==) 

      if(c<=0) return true;

      return false;
    }
};