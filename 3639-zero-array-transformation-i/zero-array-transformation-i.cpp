class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>prefix(n,0);
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            prefix[l]--;
            if(r+1<n){
                prefix[r+1]++;
            }

        }
        for(int i = 1; i< prefix.size(); i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]+prefix[i]>0){
                return false;
            }
        }
        return true;
    }
};