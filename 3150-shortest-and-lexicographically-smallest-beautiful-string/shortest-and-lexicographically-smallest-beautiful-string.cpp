class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        string ans = "";

        int i = 0, cnt = 0, j = 0;

        for(; j<n; j++){
            if(s[j] == '1') cnt++;

            while(cnt > k){
                if(s[i] == '1') cnt--;
                i++;
            }

            if( cnt == k ){
                while(i<j && s[i] == '0'){
                    i++;
                }
                string str = s.substr(i, j - i + 1);
                if(ans == "" || str.size() < ans.size() || (ans.size()==str.size() && str<ans)){
                    ans = str;
                }
            }

        }
        

        return ans;
    }
};