class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
            int n = nums.size();
            bool sorted = true;
            int ans = 0;

            for(int i = 0; i<n-1; i++){
                if(nums[i]>nums[i+1]){
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                for(int i = 1; i<=n; i++){
                    if(n%i != 0) continue;
                    ans += i;
                }
                return ans;
            }
            for(int i = 2; i<=n; i++){
                if(n%i != 0) continue;
                int j = 0;
                int prev_mx = 0;
                bool bad = false;
                while(j<n){
                    int drops = 0;
                    int mx = nums[j], mn = nums[j];

                    for(int k = j+1; k<j+i; k++){
                        if(nums[k]<nums[k-1]) drops++;
                        mx = max(mx,nums[k]);
                        mn = min(mn,nums[k]);
                    }

                    if(nums[j+i-1]>nums[j]) drops++;

                    if(mn<prev_mx || drops > 1){
                        bad = true;
                        break;
                       
                    }
                    prev_mx = mx;
                    j += i;

                }
                if(!bad) ans += i;
            }

            return ans;
    }
};