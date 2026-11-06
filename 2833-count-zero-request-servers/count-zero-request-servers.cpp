class Solution {
public:
    vector<int> countServers(int y, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int n = logs.size(), m = queries.size();
        vector<int>ans(m);

        vector<pair<int,int>>interval;
        for(int i = 0; i<m; i++){
            interval.push_back({queries[i],i});
        }
        sort(interval.begin(), interval.end());

        sort(logs.begin(), logs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]<b[1];
        });

        unordered_map<int,int>mp;
        int st = 0, end = 0;

        for(int i = 0; i<m; i++){
            int ns = interval[i].first - x, ne = interval[i].first;
            int idx = interval[i].second;

            while(end<n && logs[end][1]<=ne){
                mp[logs[end][0]]++;
                end++;
            }

            while(st<end && logs[st][1]<ns){
                if( --mp[logs[st][0]] == 0) mp.erase(logs[st][0]);
                st++;
            }
            
            ans[idx] = y - mp.size();

        }

        return ans;
    }
};