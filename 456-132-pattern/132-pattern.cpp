class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int tp = INT_MIN;
        stack<int>st;
        for(int i = nums.size()-1; i>=0; i--){

            if(nums[i] < tp) return true;
            while(!st.empty() && nums[i]>st.top()){
                tp = max(tp,st.top());
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
       
    }
};