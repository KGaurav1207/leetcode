class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int d = 0, ans = 0;
        for(int i = 0; i<n;){
            if(s[i] == '('){
                d++;
                i++;
            }
            else if(s[i] == ')'){
                ans += pow(2,(d-1));
                while(i<n && s[i] == ')'){
                    d--;
                    i++;
                }
            }
            
        }

        return ans;
    }
};