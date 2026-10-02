class Solution {
    void rec(vector<string>&ans, int n, int o, int c, string &s){
        
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(o<n){
            s+='(';
            rec(ans,n,o+1,c,s);
            s.pop_back();
        }
        if(c<o){
            s += ')';
            rec(ans,n,o,c+1,s);
            s.pop_back();
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "";

        rec(ans,n,0,0,s);

        return ans;


    }
};