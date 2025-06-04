class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        int r= 0 ;
        int maxlen = 0;
        int n = s.size();
        vector<int>vec(256,-1);
        while(r<n){
             if(vec[s[r]]!=-1){
                if(vec[s[r]]>=l){
                    l=vec[s[r]]+1;
                }
            
             }
             int len = r-l+1;
             maxlen  = max(maxlen,len);
             vec[s[r]]=r;
             r++;
        }
        return maxlen;
    }
};