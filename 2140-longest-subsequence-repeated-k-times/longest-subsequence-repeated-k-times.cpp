class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        int i = 0;
        for (char c : s) {
            if (i < t.size() && c == t[i]) {
                i++;
            }
        }
        return i == t.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<char> candidates;
        for (auto& [c, f] : freq) {
            if (f >= k) candidates.push_back(c);
        }
        string ans;
        queue<string> q;
        for (char c : candidates) {
            q.push(string(1, c));
        }
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            string repeated;
            for (int i = 0; i < k; ++i) repeated += cur;
            if (isSubsequence(s, repeated)) {
                if (cur.size() > ans.size() || (cur.size() == ans.size() && cur > ans)) {
                    ans = cur;
                }
                for (char c : candidates) {
                    q.push(cur + c);
                }
            }
        }
        return ans;
    }
};