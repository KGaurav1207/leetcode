using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; ++i) available.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requestCount(k, 0);
        int maxRequests = 0;

        for (int i = 0; i < arrival.size(); ++i) {
            int time = arrival[i];
            while (!busy.empty() && busy.top().first <= time) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue;

            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();

            int server = *it;
            available.erase(it);
            requestCount[server]++;
            maxRequests = max(maxRequests, requestCount[server]);

            busy.emplace(time + load[i], server);
        }

        vector<int> result;
        for (int j = 0; j < k; ++j) {
            if (requestCount[j] == maxRequests) {
                result.push_back(j);
            }
        }
        return result;
    }
};