class Solution {
public:
    bool sumGame(string num) {
       int n=num.size();
       if(n%2!=0) return true;
        int f=0,fhs=0;
        int s=0,shs=0;
        for(int i=0;i<num.size();i++){
            if(i<n/2 && num[i]=='?') f++;
            else if(i<n/2 && num[i]!='?') fhs+=num[i]-'0';
            else if(i>=n/2 && num[i]=='?') s++;
            else if(i>=n/2 && num[i]!='?') shs+=num[i]-'0';
        }
        if ((f + s) % 2 == 1) return true;
        return fhs + 9*f/2 != shs + 9*s/2;
    }
};