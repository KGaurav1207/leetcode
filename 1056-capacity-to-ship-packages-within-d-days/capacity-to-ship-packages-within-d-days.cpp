/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
       // sort(weights.begin(),weights.end());
        for(auto w : weights) sum += w;

        int l = *max_element(weights.begin(), weights.end()), r = sum;
        while(l < r){
            int mid = l + (r - l) / 2;
            int curr_sum = 0;
            int day = 1;
            for(int i = 0; i < weights.size(); i++){
                if(curr_sum + weights[i] > mid){
                    day++;
                    curr_sum = 0;
                }
                curr_sum += weights[i];
            }
            if(day <= days){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

