class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word)
            freq[c]++;
        vector<int> counts;
        for (auto &[ch, cnt] : freq)
            counts.push_back(cnt);
        sort(counts.begin(), counts.end());
        int n = counts.size();
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int base = counts[i];
            int targetMin = base;
            int targetMax = base + k;
            int deletions = 0;

            for (int j = 0; j < n; ++j) {
                if (counts[j] < targetMin)
                    deletions += counts[j]; 
                else if (counts[j] > targetMax)
                    deletions += counts[j] - targetMax;
            }
            res = min(res, deletions);
        }
        return res;
    }
};