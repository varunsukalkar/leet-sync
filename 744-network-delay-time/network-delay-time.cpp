class Solution {
public:
      #define p pair<int,int>
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<p>> adj;
        priority_queue<p, vector<p>, greater<p>> pq;

        for (auto x : times) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v, w});
        }

        vector<int> res(n + 1, INT_MAX);
        pq.push({0, k});
        res[k] = 0; 

        while (!pq.empty()) {
            int u = pq.top().second;
            int first_dist = pq.top().first;
            pq.pop();

          
            if (first_dist > res[u]) continue;

            for (auto padosi : adj[u]) {
                int v = padosi.first;
                int sec_dist = padosi.second;

                if (first_dist + sec_dist < res[v]) {
                    res[v] = first_dist + sec_dist;
                    pq.push({res[v], v});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (res[i] == INT_MAX) return -1;
            ans = max(ans, res[i]);
        }

        return ans;
    }
};