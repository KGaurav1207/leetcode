class Solution {
public:
    int minSwaps(string s) {
      int open  = 0, close = 0;
      int cnt = 0;
      for (auto &x: s){
        if(x == '[') open++;
        else if(open>0 && x == ']') open--;
        else if(open == 0 && x == ']'){
            open++;
            cnt++;
        };
      }

      return cnt;  
    }
};