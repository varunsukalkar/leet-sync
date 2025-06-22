class Solution {
public:
    vector<int> partitionLabels(string s) {
    vector<int>hash(26,0);
    int n = s.size();
    vector<int>ans;
    for(int i = n-1 ; i>=0 ; i-- ){
      hash[s[i]-'a'] = max(hash[s[i]-'a'] ,i);
    }
  int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, hash[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }

 
};