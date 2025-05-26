class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        typedef pair<int,pair<int,int>> p;
        priority_queue<p,vector<p>,greater<p>>pq;
        int n = heights.size();
        int m =  heights[0].size();
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        vector<int>drow={1,0,-1,0};
        vector<int>dcol = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it .second.second;
            if(row==n-1 && col ==m-1){
                return diff;
            }
            for(int i  = 0 ;i< 4 ; i++){
                int newr = drow[i]+row;
                int newc = dcol[i]+col;
                
                if(newr>=0 && newc >= 0 && newr<n && newc <m ){
                    int neweffort = max(abs(heights[row][col]- heights[newr][newc]),diff);
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc]=neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }

return 0;
    }
};