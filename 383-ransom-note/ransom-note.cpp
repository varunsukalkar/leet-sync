class Solution {
public:
    bool canConstruct(string a, string b) {
       map<char , int>map;
       for(int i  = 0 ; i< b.size(); i++){
           map[b[i]]++;
       }
       for(int i = 0 ; i< a.size(); i++){
        if(map.find(a[i])!=map.end()){
            map[a[i]]--;
            if(map[a[i]]==0){
                map.erase(a[i]);
            }
        }
        else{
            return false;
        }

       }
        return true;
    }
};