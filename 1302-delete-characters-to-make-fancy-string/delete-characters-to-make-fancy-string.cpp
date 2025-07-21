class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3){
            return s;
        }
        string str = "";
        for(int i = 0 ; i< s.size(); i++){
            if(i<s.size()-2 && s[i]==s[i+1]&& s[i+1]==s[i+2]){
               continue;
            }else{
            str+=s[i];
            }
        }
        
        return str;







    }
};