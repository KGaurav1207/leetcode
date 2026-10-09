class Solution {
    
    int n;
    unordered_set<int>st;
    vector<vector<int>>ans;

    void solve(vector<int>&nums, vector<int>&temp){

        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i<n; i++){

            if(st.find(nums[i]) != st.end()) continue;

            temp.push_back(nums[i]);
            st.insert(nums[i]);
            solve(nums,temp);

            temp.pop_back();
            solve(nums,temp);
            st.erase(nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>temp;
        solve(nums,temp);

        return ans;
    }
};