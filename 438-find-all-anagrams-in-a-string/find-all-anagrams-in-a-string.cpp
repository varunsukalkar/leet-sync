class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()){
            return {};
        }
           vector<int>ans(26,0);
           vector<int>result(26,0);
           vector<int>finalans;
          for(int i =0 ; i< p.size(); i++){
               result[s[i]-'a']++;
              ans[p[i]-'a']++;
          }


           if(result==ans){
            finalans.push_back(0);
           }
         for(int i = p.size(); i<s.size(); i++){


            result[s[i]-'a']++;
            result[s[i-p.size()]-'a']--;

            if(result==ans){
                finalans.push_back(i+1-p.size());
            }
         }
         return finalans;
    }
};