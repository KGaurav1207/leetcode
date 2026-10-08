class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0, close = 0 ;
        string substr = "", ans = "";
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                if(open >= 1) substr += s[i];
                open++;
            }
            else{
            substr += s[i];
            open--;
            }
            if(open == 0 ){
             substr.pop_back();
             ans += substr ;
             substr = "";
            }
        }
        return ans;
    }
};