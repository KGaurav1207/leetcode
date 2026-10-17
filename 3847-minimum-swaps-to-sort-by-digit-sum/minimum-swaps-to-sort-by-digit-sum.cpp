class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,pair<int,int>>>p;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int val = nums[i];
            int original = val;
            int sum = 0;
            while(val>0){
                sum += val%10;
                val/=10;
            }
            p.push_back({sum,{original,i}});

        }

        sort(p.begin(), p.end());

        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[p[i].second.first] = i;
        }

        int ans = 0;
        int i = 0;
      for (int i = 0; i < n; i++) {
        while (p[i].second.second != i) {
        int idx = p[i].second.second;

        swap(nums[i], nums[idx]);
        swap(p[i].second.second, p[idx].second.second);
        ans++;
       }
}
        return ans;
    }
};