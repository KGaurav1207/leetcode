class Solution {
public:
    bool checkDivisibility(int n) {
      int x = n;
      int sum = 0, mult = 1;

      while(x>0){
        int dig = x%10;
        sum += dig;
        mult *= dig;
        x /= 10;
      }  
      sum += mult;

      return n%sum == 0;
    }
};