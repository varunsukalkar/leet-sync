class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>>pos(26);
        for(int i = 0 ; i< n; i++){
               if(s[i]=='*'){
                              for(int j = 0 ; j< 26; j++){
                                if(pos[j].size()>0){
                                    s[pos[j].back()]='*';
                                    pos[j].pop_back();
                                    break;

                                }
                              }


               }
               else{
                pos[s[i]-'a'].push_back(i);
               }


        }

        string res="";
        for(int i = 0; i< s.size(); i++){
            if(s[i]!='*'){
                res+=(s[i]);
            }
        }
       return  res;
    }
};