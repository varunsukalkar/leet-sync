class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
       int maxi =  *max_element(c.begin(),c.end());
       vector<bool>ans(c.size(),false);
       for(int i = 0 ; i< c.size(); i++){
        if(ec+c[i]>=maxi){
            ans[i]=(true);
        }
       }
       return ans;
    }
};