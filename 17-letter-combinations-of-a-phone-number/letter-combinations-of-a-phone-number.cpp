class Solution {
public:
    vector<string> letterCombinations(string digits) {
       unordered_map<int,string>mp;

       char j = 'a';
      
       for(int i = 2; i<=9; i++){
        int cnt = 0;
        string s = "";
            for( ; j<='z' && cnt<3;j++){
                s += j;
                cnt++;
            }
            if(i == 7){
                s += j;
                j++;
            }
            else if( i == 9){
                s += j;
                j++;
            }
            mp[i] = s;
       } 

       vector<string> temp;
       for(auto &ch : digits){
        temp.push_back(mp[ch-'0']);
       }
        vector<string>comb;
        vector<string>ans;
        int len = digits.size();
       for(int i = 0; i<temp[0].size(); i++){
        string s = "";
        s += temp[0][i];
        comb.push_back(s);
        if(s.size() == len) ans.push_back(s);

       }

       for(int i = 1; i<temp.size(); i++){
        int n = comb.size();
        for(int j = 0; j<temp[i].size(); j++){
            for(int k = 0; k<n; k++){
                string s = comb[k];
                s += temp[i][j];
                comb.push_back(s);
                if(s.size() == len) ans.push_back(s);
            }
        }
       }

       return ans;

    }
};