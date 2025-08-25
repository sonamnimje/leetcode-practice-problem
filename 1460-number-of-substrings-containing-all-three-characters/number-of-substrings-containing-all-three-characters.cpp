class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> count(3, 0); // counts for a, b, c
        int left = 0, right = 0;
        int result = 0;

        while (right < n) {
            count[s[right] - 'a']++;  
            // shrink window while it still has all 3 chars
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) 
            {
                result += n - right;        // all substrings starting at left are valid
                count[s[left] - 'a']--;  // remove s[left] and move left
                left++;
            }

            right++;  // expand window
        }

        return result;
    }
};