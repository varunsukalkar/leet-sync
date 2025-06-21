class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         vector<vector<pair<int, int>>> adj(n); // node -> (neighbor, color)
        for (auto& e : redEdges) adj[e[0]].push_back({e[1], 0}); // 0 = red
        for (auto& e : blueEdges) adj[e[0]].push_back({e[1], 1}); // 1 = blue

        vector<int> redDist(n, 1e9), blueDist(n, 1e9);
        queue<pair<int, int>> q; // {node, color}

        redDist[0] = blueDist[0] = 0;
        q.push({0, 0}); // start with red
        q.push({0, 1}); // start with blue

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            for (auto [next, edgeColor] : adj[node]) {
                if (edgeColor == color) continue; // skip same color to alternate

                if (edgeColor == 0 && redDist[next] == 1e9) {
                    redDist[next] = blueDist[node] + 1;
                    q.push({next, 0});
                }
                if (edgeColor == 1 && blueDist[next] == 1e9) {
                    blueDist[next] = redDist[node] + 1;
                    q.push({next, 1});
                }
            }
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int minDist = min(redDist[i], blueDist[i]);
            res[i] = (minDist == 1e9) ? -1 : minDist;
        }

        return res;
    
    }
};