class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int current = 0 ;
        int ans = 0 ;
        int maxelement = 0 ;
        for(int  i  : nums){
            if(maxelement<i){
                maxelement= i ;  
                current= 0 ;
                ans = 0 ;
            }
            if(maxelement==i){
                    current++;
            }
            else{
                    current = 0 ;
            }
            ans = max(ans , current);
        }
        return ans;
    }
};