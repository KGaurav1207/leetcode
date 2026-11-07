class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        // free servers: (weight, index), smallest weight first, then smallest index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> serverPool;

        // busy servers: (time when free, index), earliest free time first
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> serverOccupied;

        // add all servers to the free pool
        for (int i = 0; i < n; i++) {
            serverPool.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;   // long long: time can grow up to about m * max(task)

        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);   // task i only arrives at second i if it is waiting for server to be free

            // no free server: jump time to when the first busy server is free
            if (serverPool.empty()) {
                time = max(time, (long long)serverOccupied.top().first);
            }

            // free every server whose finish time is <= current time
            while (!serverOccupied.empty() && serverOccupied.top().first <= time) {
                int idx = serverOccupied.top().second;
                serverOccupied.pop();
                serverPool.push({servers[idx], idx});
            }

            // pick the best free server
            int idx = serverPool.top().second;
            serverPool.pop();

            ans[i] = idx;
            serverOccupied.push({(int)(time + tasks[i]), idx});
        }
        return ans;
    }
};