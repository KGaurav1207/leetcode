class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
      unordered_map<string,string>mp;
      vector<pair<int,int>>p;
        int n = s.size();
        int x,y;

        for(int i = 0; i<k.size(); i++){
            mp[k[i][0]] = k[i][1];
        }

        for(int i = 0; i<n; i++){
            if(s[i] == '(') x = i;
            else if(s[i] == ')'){
                y = i;
                p.push_back({x,y});
            }
        }
        string res = "";
        int prev = 0;
        for(int i = 0; i<p.size(); i++){
            
           int x = p[i].first;
           int y = p[i].second;
           res += s.substr(prev, p[i].first-prev);
           prev = y+1;
           string str = s.substr(x+1, y-x-1);
           if(mp.find(str)!=mp.end()) res += mp[str];
           else res += "?";
        }
        //int l = p[p.size()-1].second+1;
        //res += s.substr(l,s.size() - l );
        res += s.substr(prev);

        return res;

    }
};