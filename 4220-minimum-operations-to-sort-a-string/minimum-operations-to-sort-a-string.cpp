class Solution {
    bool sorted(string s){
        for(int i = 1; i<s.size(); i++){
            if(s[i]<s[i-1]) return false;
        }

        return true;
    }
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 0 || sorted(s)) return 0;
        if(n == 2) return -1;
        int mn = 27, mx = -1, mnidx = 0, mxidx = 0;
        for(int i =  0; i<n; i++){
            if(mn>s[i]-'a'){
                mn = s[i] - 'a';
                mnidx = i;
            }
            if(mx<=s[i]-'a'){
                mx = s[i]-'a';
                mxidx = i;
            }
        }
        if(mnidx == 0 || mxidx == n-1) return 1;
        
        if(mxidx > 0 || mnidx < n-1) return 2;

        return 3;

    }
};