class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
       double ans = 0;

       sort(p.begin(),p.end(),greater());
       sort(d.begin(),d.end(),greater());

       int i = 0;

       for(; i<min(p.size(),d.size()) ; i++){
        ans += (double)(p[i] * (100 - d[i])  / 100.0);
       }
       while(i<p.size()){
        ans += p[i];
        i++;
       } 

       return ans;

    }
};