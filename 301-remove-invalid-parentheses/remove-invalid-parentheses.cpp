class Solution {
    bool check(string s) {
        int open = 0;

        for(auto &ch : s) {
            if(ch >= 'a' && ch <= 'z')
                continue;

            if(ch == '(')
                open++;
            else if(open > 0)
                open--;
            else
                return false;
        }

        return open == 0;
    }

    void rec(string &s, string &cur, int include, int idx,
             priority_queue<pair<int,string>>& p) {

        
        if(idx == s.size()) {
            if(check(cur)) {
                p.push({include, cur});
            }
            return;
        }

        
        if(s[idx] >= 'a' && s[idx] <= 'z') {

            cur.push_back(s[idx]);

            rec(s, cur,include + 1, idx + 1, p);

            cur.pop_back();
        }
        else {

            
            cur.push_back(s[idx]);

            rec(s, cur,include + 1, idx + 1, p);

            cur.pop_back();

            
            rec(s, cur,include, idx + 1, p);
        }
    }

public:
    vector<string>removeInvalidParentheses(string s) {

        priority_queue<pair<int,string>> p;

        string cur;

        rec(s, cur, 0, 0, p);

        vector<string> ans;

        if(p.empty())
            return {""};

        
        int t = p.top().first;

        set<string> st;

        while(!p.empty()) {

            if(p.top().first == t) {
                st.insert(p.top().second);
                p.pop();
            }
            else {
                break;
            }
        }

        for(auto &str : st)
            ans.push_back(str);

        return ans;
    }
};