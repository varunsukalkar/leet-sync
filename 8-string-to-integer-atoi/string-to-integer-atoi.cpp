class Solution {
public:
    int myAtoi(string s) {
     int i = 0, n = s.size();
    while (i < n && s[i] == ' ') i++;  // Skip leading spaces

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    long long number = 0;
    while (i < n && isdigit(s[i])) {
        number = number * 10 + (s[i] - '0');
        
        // Clamp if out of int range
        if (sign == 1 && number > INT_MAX) return INT_MAX;
        if (sign == -1 && -number < INT_MIN) return INT_MIN;

        i++;
    }

    return sign * number;
    }
};