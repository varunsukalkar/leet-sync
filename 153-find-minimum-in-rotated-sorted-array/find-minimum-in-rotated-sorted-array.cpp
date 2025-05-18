class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 ;
        int ans=INT_MAX;
        int high = arr.size()-1;
      
        while(low<=high)
        {
            if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;


        }
            int mid=(low+high)/2;
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                high=mid-1;
            }


        }
        return ans;
    }
};