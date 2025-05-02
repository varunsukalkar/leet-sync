class Solution {
public:
    string pushDominoes(string s) {
        s = 'L' + s + 'R';
        string res;

        int prev = 0;
        for (int curr = 1; curr < s.size(); ++curr) {
            if (s[curr] == '.') {
                continue;
            }

            int span = curr - prev - 1;
            if (prev > 0) 
                res += s[prev];

            if (s[prev] == s[curr]) {
                res += string(span, s[prev]);
            }
            else if (s[prev] == 'L' && s[curr] == 'R') {
                res += string(span, '.');
            }
            else { 
                res += string(span / 2, 'R')
                     + string(span % 2, '.')
                     + string(span / 2, 'L');
            }
            prev = curr;
        }
        return res;
    
    }
};