class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     for(int &x: nums){
        mp[x]++;
     }   

     int i = 2, x = k;
     while(true){
        if(mp.count(x) == 0) return x;
        x = k*i;
        i++;
     }

     return 0;
    }
};