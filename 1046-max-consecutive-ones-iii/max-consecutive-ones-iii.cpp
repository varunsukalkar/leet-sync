class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
   int l = 0 ;
   int r = 0 ; 
   int n = nums.size();
   int zero = 0;
   int maxlen=0;
       while(r<n){
        if(nums[r]==0){
            zero++;
        }
    if(zero>k){
        
        while(zero>k){
            if(nums[l]==0){
                zero--;
            }
                l++;
            
        }
    }
    if(zero<=k){
        maxlen=max(maxlen,r-l+1);
    }
        r++;

    }
       
   return maxlen;
       
    }
};