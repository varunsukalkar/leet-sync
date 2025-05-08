class Solution {
public:
  
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int j = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+j);
        reverse(nums.begin()+j , nums.end());
     
        
    }
};