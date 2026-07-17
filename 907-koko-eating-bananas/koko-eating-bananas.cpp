/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mn = 1;
        int mx = *max_element(piles.begin(), piles.end());
        while(mn<mx){
            int mid = mn + (mx-mn)/2;
            long long time = 0;
            for(int i=0;i<piles.size();i++){
                time += (piles[i]+mid-1)/mid;
            }
            if(time>h){
                mn = mid+1;
            }else{
                mx = mid;
            }
        }
        return mn;
    }
};
// @lc code=end

