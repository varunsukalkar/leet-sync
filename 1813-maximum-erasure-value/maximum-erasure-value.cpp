class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n  = nums.size();
       unordered_set<int> set;
       int sum = 0 ; 
       int currentsum = 0 ;
       int left = 0 ; 

       for(int right = 0 ; right< n; right++){
        while(set.find(nums[right])!=set.end()){
            currentsum-=nums[left];
            set.erase(nums[left]);
            left++;
        }
       
        currentsum+=nums[right];
         set.insert(nums[right]);
        sum= max(currentsum , sum);
       }
       return sum;
    }
};