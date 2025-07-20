class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0 ;
        long long number = 0 ;
        int sign = 1;
        while(i< n && s[i]==' ' ){
           
          i++;
        }
        if(i< n && (s[i]=='+' || s[i]=='-')){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }

         

        while(i< n && isdigit(s[i])){
            number = number * 10 + (s[i]-'0');
            if(sign == 1 &&  number>INT_MAX) return INT_MAX;
            if(sign == -1 && -number<INT_MIN)return INT_MIN;
            i++;
        }
        return sign * number ; 













        
    }
};