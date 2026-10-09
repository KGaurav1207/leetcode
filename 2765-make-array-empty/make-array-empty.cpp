class Solution {
public:
    using ll = long long;
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pair<int,int>>temp;
        ll n = nums.size();
        for(int i = 0; i<n; i++){
            temp.push_back({nums[i],i});
        }

        sort(temp.begin(), temp.end());

        ll ans = n; 

        for(int i = 1; i<n; i++){
            
            if(temp[i].second < temp[i-1].second) ans += n-i;
        }


        return ans;
        
    }
};