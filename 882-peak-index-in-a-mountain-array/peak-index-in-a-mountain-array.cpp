class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size()-1;
       if(arr[0]>arr[1]){
        return 0;
       }
       if(arr[n-2]<arr[n-1]){
        return n-1;
       }

       int low = 1;
       int high = n-1;
       while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;

        }
        else if(arr[mid]<arr[mid+1]){
            low = mid+1;

        }
        else{
            high = mid-1;
        }
       }
       return high;
    }
};