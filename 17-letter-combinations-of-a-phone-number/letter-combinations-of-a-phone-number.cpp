class Solution {
    vector<string>ans;

    void fun(vector<string>&comb, string dig, string s,int idx){
        if(s.size() == dig.size()){
            ans.push_back(s);
            return;
        }

        for(int i = 0; i<comb[dig[idx] - '2'].size(); i++){
            fun(comb, dig, s + comb[dig[idx] - '2'][i], idx+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> comb = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        fun(comb, digits, "", 0);

        return ans;
    }
};