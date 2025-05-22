class Solution {
public:


 bool dsf(int i ,vector<vector<int>>&adj ,vector<int> & visited, vector<int> & pathvisited , 
  vector<int> & check){
      visited[i]=1;
      pathvisited[i]=1;
      check[i]=0;
      for(auto it :adj[i]){
          if(!visited[it]){
              if(dsf(it,adj,visited,pathvisited,check)==true){
                  check[i]=0;
                  return true;
              }
          }
              else if(pathvisited[it]){
                  check[i]=0;
                  return true;
              }
          
      }
      check[i]=1;
      pathvisited[i]=0;
      return false;
      
      
  }
    vector<int> eventualSafeNodess(int V, vector<vector<int>>& adj) {
        // code here
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        
        
        for(int i = 0 ; i< V; i++){
            if(visited[i]==0){
                dsf(i , adj,visited,pathvisited,check);
                
            }
        }
        for(int i =0 ; i< V; i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       return  eventualSafeNodess(graph.size(),graph);
    }
};