class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool nonzero = false;
        for(auto  &x:nums){
            if(x!=0) nonzero = true;
            ans ^= x;
        }

        if(ans!=0) return n;

        if(nonzero) return n-1;


        return 0;

    }
};