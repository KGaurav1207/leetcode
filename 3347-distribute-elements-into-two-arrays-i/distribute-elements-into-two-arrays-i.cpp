class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>temp;
        ans.push_back(nums[0]);
       temp.push_back(nums[1]);

        for(int i = 2; i<n; i++){
           if(ans.back()>temp.back()){
            ans.push_back(nums[i]);
           }
           else{
            temp.push_back(nums[i]);
           }
        }

        for(auto &x: temp){
            ans.push_back(x);
        }

        return ans;
    }
};