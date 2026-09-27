class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int f = -1;
        
        string res = "";

        for(int i = 0; i<s.size(); i++){

            if(s[i] == '(') st.push(s[i]);

            else if(s[i] == ')'){

                string str = "";

                while(st.top()!='('){
                    str = st.top() + str;
                    st.pop(); 
                }

                st.pop();
                reverse(str.begin(),str.end());

                if(!st.empty()){
                    for(char ch : str){
                        st.push(ch);
                    }
                }

                else res += str;
            }

            else if(!st.empty()){
                st.push(s[i]);
            }
            
            else if(st.empty()){
                res += s[i];
            } 
        }

        return res;
       
    }
};