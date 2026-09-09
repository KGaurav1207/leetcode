class Solution {
    using ll = long long;
public:
    long long countCommas(long long n) {
        ll k = 0, ans = 0;
        ll p = n;
        while(p>0){
            k++;
            p/=10;
        }

        for(int i = 1; i<=5; i++){
            if(k>=(3*i+1)){
                ll least = 1;
                for(int j = 0; j<3*i; j++){
                    least *= 10;
                }
                ans += n - least + 1;
            }
        }

        return ans;
    }
};