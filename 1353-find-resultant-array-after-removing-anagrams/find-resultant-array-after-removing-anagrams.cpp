class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = ""; // Store sorted version of previous word

        for (int i = 0; i < words.size(); i++) {
            string sortedWord = words[i];
            sort(sortedWord.begin(), sortedWord.end());

            if (i == 0 || sortedWord != prevSorted) {
                result.push_back(words[i]); // Keep the word
                prevSorted = sortedWord;    // Update previous sorted word
            }
            // If sortedWord == prevSorted, it is an anagram of previous word, so skip
        }

        return result;
    }
};