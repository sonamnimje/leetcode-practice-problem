class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char ch) {
            string vowels = "aeiouAEIOU";
            return vowels.find(ch) != string::npos;
        };
        
        // Step 1: extract vowels
        vector<char> vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        
        // Step 2: sort vowels
        sort(vowels.begin(), vowels.end());
        
        // Step 3: place back sorted vowels
        int j = 0;
        for (char &ch : s) {
            if (isVowel(ch)) {
                ch = vowels[j++];
            }
        }
        
        return s;
    }
};