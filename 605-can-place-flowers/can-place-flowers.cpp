class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        if(n==0){
            return true;
        }
        if(arr.size()==1){
            if(arr[0]==0 && n==1){
                return true;
            }
            
            else{
                return false;
            }
        }
        for(int i = 0 ; i<arr.size() && n>0; i++){
            if(i == 0 ){
                if(arr[i]== 0 && arr[i+1]==0 && n>0){
                    arr[i]=1;
                    n--;
                }
            }
            if(n==0){
                return true;
            }
            if(i== arr.size()-1){
                if(arr[i]== 0 && arr[i-1]==0 && n>0){
                    arr[i]=1;
                    n--;
                }
            }
            if(i!= 0 && arr[i]==0 && i!=arr.size()-1)
            {
                if(arr[i-1]==0 && arr[i+1]==0 && n>0){
                    arr[i]=1;
                    n--;
                }
            }
        }
       return n<=0;
    }
};