class Solution {
public:
    int minInsertions(string s) {
      int ans = 0, open = 0, n = s.size();
      for(int i = 0; i<n;){
        if(s[i] == '('){
            open++;
        }
        else{
            if(i<n-1 && s[i+1] == ')' ){
                if(open>0) open--;
                else ans++;
                i++;
                //i++;
            }
            else{
                ans++;
                if(open>0) open--;
                else ans++;
            }
        }
        i++;
      }
      if(open<0) ans += -(open);
      else ans += 2*open;

      return ans;
    }
};