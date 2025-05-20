class Solution {
public:
  
    vector<int>drow ={-1,0,1,0} ;
    vector<int>dcol={0,1,0,-1};

    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int n ,int m, int row ,int col){
        visited[row][col]=1;
        for(int i = 0 ; i<4 ; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]== 0 && grid[nrow][ncol]==1){
                dfs(grid,visited,n,m,nrow,ncol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i =0 ; i< m ; i++){

            // o i  
            if(visited[0][i]==0 && grid[0][i]==1){
                dfs(grid,visited,n,m,0 ,i);
            }



            // n-1 i 

            if(visited[n-1][i]==0 && grid[n-1][i]==1){
 dfs(grid,visited,n,m,n-1 ,i);
            }
        }

        for(int i = 0  ; i< n; i++){
            // i 0 
            if(visited[i][0]==0 && grid[i][0]==1){
                 dfs(grid,visited,n,m,i ,0);
            }



            // i  m-1

            if(visited[i][m-1]==0 && grid[i][m-1]){
                 dfs(grid,visited,n,m,i ,m-1);
            }
        }

    int count=0;
        for(int i = 0 ; i< n;i++){
            for(int j = 0 ; j< m; j++){
               if(visited[i][j]==0 && grid[i][j]==1){
                count++;
               }
            }
        }
        return count;
    }
};