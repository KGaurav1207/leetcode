class Solution {
    bool check_sum(vector<int> &nums, int l, int r){
        vector<int>ans(501,0);
        for(int i = l; i<=r; i++){
            ans[nums[i]]++;
        }

        for(int i = 1; i<500; i++){
            if(ans[i]<=0) continue;
            if(ans[i] >= 2) {
                int sum = i + i;

                if(sum <= 500 && ans[sum] > 0)
                    return true;
            }
            for(int j = i+1; j<501; j++){
                if(ans[j] <= 0) continue;

                int sum = i+j;
                if(sum<=500 && ans[sum]>0) return true;
            }
        }

        return false;
    }
    
public:
    int maxSubarray(vector<int>& nums) {
       int n = nums.size();
       int i = 0, j = 2;
       int ans;
       ans = min(2,n);

       while(j<n){
        if(check_sum(nums,i,j)){
            i++;
            j++;
        }
        else{
            ans = max(ans,j-i+1);
            j++;
        }
       }

       return ans;
    }
};