class Solution {
public:
    int minAddToMakeValid(string s) {
      int ans = 0, close = 0, open = 0;
      for (auto &x: s){
        if(x == '(') open++;
        if(open == 0 && x == ')') ans++;
        if(open > 0 && x == ')') open--;
      } 


      return ans + open;
    }
};