class Solution {

    int fun(string &s, int n, int st, int end,int k){
        if(end-st < k) return 0;

        vector<int>freq(26,0);
        for(int i = st; i<end; i++){
        freq[s[i]-'a']++;
        }

        for(int i = st; i<end; i++){
            if(freq[s[i]-'a'] < k){
                int j = i+1;
               

                while(j<n && freq[s[j] - 'a']<k){
                    j++;
                }

                return max(fun(s,n,st,i,k), fun(s,n,j,end,k));
            }
        }

        return end - st;
        


    }
public:
    int longestSubstring(string s, int k) {
      return fun(s,s.size(), 0, s.size(),k);
    }
};