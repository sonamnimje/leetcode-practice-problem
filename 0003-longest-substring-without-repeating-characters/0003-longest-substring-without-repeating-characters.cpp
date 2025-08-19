class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char>window;
        int start = 0;
        int maxlen = 0;
        //traverse the loop
        for(int end =0; end<n;end++)
        {
            //removing duplicate char
            while(window.count(s[end])){
                window.erase(s[start]);
                start++;
            }
            //add new elemnt in set
        window.insert(s[end]);
        maxlen = max(maxlen,end-start+1);
        }
        return maxlen;
    }
};