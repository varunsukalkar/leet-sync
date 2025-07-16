class Solution {
public:
    int maximumLength(vector<int>& nums) {
         vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(nums[i] % 2);  // Store parity
        }

        int odd = 0, even = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == 1) odd++;
            else even++;
        }

        int alt = 1;
        int parity = vec[0];
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] != parity) {
                parity = vec[i];
                alt++;
            }
        }

        return max({alt, odd, even});  // Return the maximum of all 3
    
    }
};