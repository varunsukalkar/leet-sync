class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set = {'A','E','I','O','U','a','e','i','o','u'};
        string str = "";
        for(int i = 0 ;i< s.size(); i++){
            if(set.find(s[i])!=set.end()){
                str+=s[i];
               

            }
        }
        reverse(str.begin(),str.end());
        int k = 0 ;
        for(int i = 0 ; i< s.size(); i++){
            if(set.find(s[i])!=set.end()){
                 s[i]=str[k];
                 k++;
            }
        }
        return s;
    }
};