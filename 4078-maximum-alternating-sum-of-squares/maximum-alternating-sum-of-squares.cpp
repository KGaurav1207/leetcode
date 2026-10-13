class Solution {
public:
    using ll = long long; 
    long long maxAlternatingSum(vector<int>& nums) {
        ll ans = 0, n = nums.size();
        sort(nums.begin(),nums.end(),[](auto& a, auto& b){
            return abs(a) < abs(b);
        });
        int i = 0, j = n-1;
        while(i<j){
            ans -= nums[i]*nums[i];
            ans += nums[j]*nums[j];
            i++;
            j--;
        }
        if(i == j) ans += nums[i]*nums[i];

        return ans;
    }
};