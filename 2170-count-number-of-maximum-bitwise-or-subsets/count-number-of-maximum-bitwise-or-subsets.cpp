class Solution {
public:

    int countsubsets(int idx, int curror , vector<int> &nums, int maxor , vector<vector<int>>& t ){
        if(idx ==nums.size()){
            if(curror==maxor){
                return 1;
            }
            return 0;
        }
        if(t[idx][curror]!=-1){
            return t[idx][curror];
        }
        int takecount = countsubsets(idx+1, curror|nums[idx] , nums,maxor, t);
        int nottakecount = countsubsets(idx+1,curror,nums,maxor,t);
        return t[idx][curror]=takecount+nottakecount;
    }

















    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        for(int & num:nums){
            maxor|=num;
        }
        int n = nums.size();
        vector<vector<int>>t(n+1,vector<int>(maxor+1,-1));
        int curror = 0;
        return countsubsets(0,curror,nums,maxor,t);
    }
};