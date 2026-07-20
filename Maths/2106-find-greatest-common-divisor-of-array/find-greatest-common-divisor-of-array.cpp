class Solution {
    int gcd(int a, int b){
      while(b>0){
        int temp = b;
        b = a%b;
        a = temp;
      }
      return a;
    }
public:
    int findGCD(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());


        return gcd(mn,mx);
        
    }
};