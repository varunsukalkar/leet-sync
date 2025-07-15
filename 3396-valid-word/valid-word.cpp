class Solution {
public:
    bool isValid(string s) {
           int n = s.length();
        if (n < 3) return false;

        int vowels = 0, consonants = 0;
        string vowelList = "aeiouAEIOU";

        for (char c : s) {
            if (isalpha(c)) {
                if (vowelList.find(c) != string::npos) {
                    vowels++;
                } else {
                    consonants++;
                }
            } else if (!isdigit(c)) {
                return false; // invalid character
            }
        }

        return vowels >= 1 && consonants >= 1;
    
    }
};