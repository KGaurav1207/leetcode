class Solution {
    bool solve(string s, string locked, int l) {
        int n = s.size();
        int bal = 0, freeCnt = 0;

        if(n & 1)
            return false;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0')
                freeCnt++;                        
            else if((s[i] == '(') == (l == 0))
                bal++;                              
            else
                bal--;                              

                
            if(bal + freeCnt < 0)
                return false;
        }
        return true;
    }

public:
    bool canBeValid(string s, string locked) {
        if(!solve(s, locked, 0))
            return false;

        reverse(s.begin(), s.end());
        reverse(locked.begin(), locked.end());

        return solve(s, locked, 1);
    }
};