class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> freq(101, 0);

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        while(true) {
            bool flag = false;

            for(int i = 0; i < 101; i++) {
                if(freq[i] > 0) {
                    ans.push_back(i);
                    flag = true;
                    freq[i]--;
                }
            }

            if(!flag) break;
        }

        return ans;
    }
};