class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        map<char, int>freq;
        int ans=0;
        int i=0, j=0;
        for(j=0;j<n;j++)
        {
            freq[s[j]]++;
            //check all 3 char is present
            while(freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0)
            {
                ans += n-j;
                freq[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};