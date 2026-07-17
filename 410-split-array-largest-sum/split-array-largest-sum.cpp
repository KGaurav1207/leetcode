/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0;
        for(auto &x:nums){
            sum += x;
        }

        int l = *max_element(nums.begin(), nums.end()), r = sum;

        while(l<=r){
            int mid = l + (r-l)/2;
            int sum = 0, part = 1;

            for(auto & x: nums){
                if(sum + x > mid){
                    part++;
                    sum = 0;
                }
                sum += x;
            }

            if(part <= k) r = mid - 1;
            else l = mid + 1;
        }

        return l;
    }
};
// @lc code=end

