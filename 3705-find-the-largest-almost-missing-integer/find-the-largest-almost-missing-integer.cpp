class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);

        if(k==nums.size()) return *max_element(nums.begin(), nums.end());

        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int ans = -1;

        if(k==1){
            for(auto & x: nums){
                if(freq[x] == 1) ans = max(ans,x);
            }

            return ans == -1? -1: ans;
        }
        int a1 = nums[0], a2 = nums[nums.size()-1];
        if(freq[max(a1,a2)] == 1) return max(a1,a2);
        if(freq[min(a1,a2)] == 1) return min(a1,a2);

        return -1;
    }
};