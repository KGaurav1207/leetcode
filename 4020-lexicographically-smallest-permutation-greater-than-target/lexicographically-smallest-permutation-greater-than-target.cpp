class Solution {
    void solve(int i, int n, string s, string t, vector<int>&freq, string &mini){
        if( i == n){
            if(s>t) mini = min(s,mini);
            return;

        }

        if(freq[t[i] - 'a'] > 0){
            freq[t[i] - 'a']--;
            solve(i+1, n, s+t[i], t, freq, mini);
            freq[t[i] - 'a']++;
        }

        for(int j = t[i] - 'a' + 1; j < 26; j++){
            if(freq[j]>0){
                s += j + 'a';
                freq[j]--;
            

            for(int k = 0; k<26; k++){
                while(freq[k] > 0){
                    s += k + 'a';
                    freq[k]--;
                }
            }

            mini = min(s, mini);
            return;
            }
        }

    }
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int>freq(26,0);

        string maxi = s;
        sort(maxi.begin(), maxi.end(), greater<char>());

        if(maxi <= target) return "";

        for(auto &x: s){
            freq[x - 'a']++;
        }

        string mini = maxi;

        solve(0, target.size(), "", target, freq, mini); 

        return mini;
    }
};