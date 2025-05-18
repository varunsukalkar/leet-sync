class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size()-1;
        int low = 0;
        int high = n;
        int ans = INT_MAX;
        if(nums[low]<nums[high]){
            return nums[low];
        }
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else if(nums[mid]<nums[high]){
                high = mid;
            }
            else{
                high -- ;
               
            }
        }
        return nums[high];
    }
};