class Solution {
public:
    int countCommas(int n) {
        int k = 0, ans = 0;
        int p = n;
        while(p>0){
            k++;
            p/=10;
        }

        if(k>=4){
            ans = n - 1000 + 1;
        }


        return ans;
    }
};