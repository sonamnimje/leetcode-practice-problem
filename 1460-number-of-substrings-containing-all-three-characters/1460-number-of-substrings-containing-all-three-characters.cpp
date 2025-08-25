class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.size();
        vector<int>count(3,0);
        int left=0, right=0;
        int result=0;

        while(right<n)
        {
            count[s[right]-'a']++;
            while(count[0]>0 && count[1]>0 && count[2]>0)
        {
            result += n-right;
            count[s[left]-'a']--;
            left++;
        }
        right++;
        }
        return result;
    }
};