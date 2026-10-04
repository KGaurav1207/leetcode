class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, cnt = 0;
        stack<int>o,st;

        for(int i = 0; i<s.size(); i++) {
            char ch = s[i];
            if(ch == '(') {
                o.push(i);
            }
            else if(ch == '*') {
                st.push(i);
            }
            else { 
                if(!o.empty()) {
                    o.pop();
                }
                else if(!st.empty()) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        
        while(!o.empty() && !st.empty()) {
            if( o.top() > st.top() ) return false;
            o.pop();
            st.pop();
        }

        return o.size() == 0;
    }
};