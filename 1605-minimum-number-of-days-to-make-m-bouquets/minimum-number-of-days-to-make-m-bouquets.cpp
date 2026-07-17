/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        ll n = bd.size();
        ll s = 1LL*m*k;
        if (s > n) return -1;
        int l = 1, r = *max_element(bd.begin(), bd.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            int g = m;
            for(int i = 0; i < n;i++) {
                if (bd[i] <= mid) {
                    cnt++;
                    if(cnt == k) {
                        g--;
                        cnt = 0;
                    }
                } else {
                    cnt = 0;
                }
            }
            if(g <= 0){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

