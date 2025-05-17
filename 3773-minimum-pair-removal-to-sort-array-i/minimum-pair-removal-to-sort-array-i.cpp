class Solution {
public:

    bool issorted(vector<int>nums){
        for(int i = 1 ; i< nums.size(); i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        if(issorted(nums)){
            return 0;
        }
        int opr=0;
       while(!issorted(nums)){

           int minindex = -1 ;
           int mincost = INT_MAX;
           for(int i = 0; i< nums.size()-1 ; i++){
               int pair = nums[i] + nums[i+1];
               if(mincost>pair){
                   mincost = pair;
                   minindex= i;
               }
           }



           int merge = nums[minindex]+nums[minindex+1];
           vector<int>vec;
           for(int i = 0; i< nums.size(); i++){
               if(i==minindex){
                   vec.push_back(merge);
                   i++;
               }
               else{
                   vec.push_back(nums[i]);
               }
               
           }
           nums=vec;
           ++opr;
       }
       
       return opr;
      
    }

};