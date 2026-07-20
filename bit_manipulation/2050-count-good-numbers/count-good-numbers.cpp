class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
    ll mpow(ll x, ll y){
        int ans = 1 ;

        while(y){

            if(y&1) ans = (1LL*ans*x)%MOD;

            x = (1LL*x*x)%MOD;

            y>>=1;
        }

        return ans;

    }
public:
    int countGoodNumbers(long long n) {
       ll eve = (n+1)/2;
       ll odd = n/2;

       ll ans = (1LL*(mpow(5,eve)%MOD)*(mpow(4,odd)%MOD))%MOD;

       return ans; 
    }
};