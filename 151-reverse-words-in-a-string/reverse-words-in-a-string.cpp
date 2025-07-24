class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        string str = "";

        for(int i  = 0 ; i< s.size(); i++){
             if(s[i]==' ' && str==""){
                continue;
             }
             else if(s[i]!=' '){
                str+=s[i];
             }
             else if(s[i]==' ' && str!=""){
                ans.push_back(str);
                str = "";
             }
            

        }
        if(str!="")
        ans.push_back(str);

        reverse(ans.begin(),ans.end());
        string l="";
         for(auto it :ans){
          l+=it;
          l+=' ';
         }
         l.pop_back();
         return l;

    }
};