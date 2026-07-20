/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt  = 0;
        int num = 0;
        for(int i = 0; i<arr.size(); i++){
            num++;
            while(num < arr[i]){
                
                cnt ++;
                if(cnt == k){
                    return num;
                }
                num ++;
            }
            
        }

        return num + k - cnt;
    }
};
// @lc code=end

