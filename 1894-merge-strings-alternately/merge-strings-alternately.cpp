class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0;
        int r = 0 ; 
        int n = word1.size();
        int m = word2.size();
        string str ="";
        while(l<n && r<m){
             if(l<n){
                str+=word1[l];
                l++;

             }
             if(r<m){
                str+=word2[r];
                r++;
             }
        }
        while(l<n){
            str+=word1[l];
            l++;
        }
        while(r<m){
            str+=word2[r];
            r++;
        }
        return str;
    }
};