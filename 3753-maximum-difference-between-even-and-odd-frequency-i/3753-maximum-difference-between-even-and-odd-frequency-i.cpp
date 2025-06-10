class Solution {
public:
    int maxDifference(string s) {
                vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        vector<int> oddFreq, evenFreq;
        for (int f : freq) {
            if (f > 0) {
                if (f % 2 == 1)
                    oddFreq.push_back(f);
                else
                    evenFreq.push_back(f);
            }
        }
        int maxDiff = INT_MIN;
        for (int o : oddFreq) {
            for (int e : evenFreq) {
                maxDiff = max(maxDiff, o - e);
            }
        }
        return maxDiff;
    }
};