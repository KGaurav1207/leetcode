class Solution {
    void rec(vector<int>& candidates, vector<vector<int>>&ans, int t,int sum, vector<int>&v,int idx){

        if(sum == t){
            ans.push_back(v);
            return;
        }
        for(int i = idx; i<candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(sum + candidates[i] > t) break;
            if(sum + candidates[i] <= t){
                v.push_back(candidates[i]);
                rec(candidates, ans, t, sum+candidates[i], v, i+1); // i+1 for dont use the same idx again
                v.pop_back();
            }
            //sum -= candidates[i];
            //v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;

        sort(candidates.begin(), candidates.end());

        rec(candidates, ans, target, 0,v, 0);

        //vector<vector<int>>res(ans.begin(), ans.end());

        // for(auto & x: ans){
        //     res.push_back(x);
        // }

        return ans;

    }
};