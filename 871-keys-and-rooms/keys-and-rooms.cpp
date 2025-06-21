class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);


        while(!q.empty()){
            auto it = q.front();
            q.pop();
            visited[it]=1;
        for(auto itt : rooms[it]){
              if(visited[itt]==0){
                q.push(itt);
              }
        }
        }
        for(int i  = 0 ; i< visited.size(); i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
};