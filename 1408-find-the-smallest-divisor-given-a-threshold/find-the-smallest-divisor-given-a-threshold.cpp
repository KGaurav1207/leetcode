class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int mn = 1, mx = *max_element(nums.begin(), nums.end());

        while(mn <= mx){
           long long mid = mn + (mx - mn)/2;

            int sum = 0;

            for(int &x:nums){
                sum += (x+mid-1)/mid;
            }

            if(sum <= threshold) mx = mid - 1;

            else mn = mid + 1;

        }

        return mx + 1;
    }
};