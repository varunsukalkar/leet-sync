class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i = 0; i< n; i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        int ans  = INT_MIN;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int node = q.front().first;
            int distance  =q.front().second;
            q.pop();
            ans  = max(ans,distance);

            for(auto it : adj[node]){
                q.push({it,distance+informTime[node]});
            }
        }









return ans;

    }
};