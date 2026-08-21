class Solution {
public:
    int minOperations(string s) {
      int ans = INT_MAX;
      int n = s.size();
      for(int i = 0; i<n; i++){
        int cost = i;
        for(int j = 0; j<n/2; j++){
            char ch1 = s[(i+j)%n];
            char ch2 = s[(i-j-1+n)%n];
            int c = abs(ch1 - ch2);
            c = min(c,26-c);
            cost += c;
        }
        ans = min(cost,ans);
      }


      return ans;
    }
};