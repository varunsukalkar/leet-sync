class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return 0;
        }
        map<char ,char> m1,m2;
        
        for(int i = 0; i< s.length();i++){
            if(m1.find(s[i])!=m1.end()){
                if(m1[s[i]]!=t[i]){
                    return 0;
                }
            }
            else if(m2.find(t[i])!=m2.end()){
                if(m2[t[i]] !=s[i] ){
                    return 0;
                }
            }
            else{
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
        }
        
     return 1;
    }
};