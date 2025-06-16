class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int minnumber = nums[0];
       int diff=-1;
       int n = nums.size();
       for(int i =  0 ; i< n; i++){
               if(nums[i]<minnumber){
                minnumber = nums[i];
               }
               else{
                diff = max(diff,nums[i]-minnumber);
               }
       }
        if( diff==0){
            return -1;
        }
        else{
            return diff;
        }
    }
};