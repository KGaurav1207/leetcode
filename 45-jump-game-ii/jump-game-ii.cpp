class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int far = nums[0];
        int near = 1;
        int cnt = 1;

        if(n<=1) return 0;

        while(far<n-1){
            int nextfar = far;
            for(int i = near; i<=far; i++){
                nextfar = max(nextfar, nums[i] + i);
            }
            near = far+1;
            far = nextfar;

            cnt++;

            //if(far >= n-1) return cnt;
        }

        return cnt;
    }
};