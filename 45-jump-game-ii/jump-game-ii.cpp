class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      int t = n-1; 
      
      vector<pair<int,int>>v;
      

      for(int i=n-2; i>=0; i--){
        if(nums[i]+i >= t){
           
            int mn = INT_MAX;
            if(nums[i] + i >= n-1){
                mn = 1;
            }
            else{
            for(int j = (int)v.size()-1; j>=0; j--){
                if(nums[i] + i >= v[j].first){
                    mn = min(mn,v[j].second+1);
                }
            }
            }
            if(mn == INT_MAX) mn = 1;
            v.push_back({i,mn});
            t = i;
        }
      } 

      if(!v.empty() && v.back().first == 0) return v.back().second;

      return 0 ;
    }
};