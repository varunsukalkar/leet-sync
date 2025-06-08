class Solution {
public:


    void solve(int currnum , int n, vector<int> & ans){
          if(currnum>n){
            return ;
          }
            ans.push_back(currnum);
          
          for(int i = 0; i<= 9 ; i++){
            int newnum = (currnum*10)+i;
            if(newnum>n){
                return ;
            }
            solve(newnum,n,ans);
          }







    }









    vector<int> lexicalOrder(int n
    ) {
        vector<int>ans;
        for(int i = 1 ; i<=9 ; i++){
            solve(i , n, ans);
     
        }
        return ans ;
    }
};