class Solution {
public:
    string robotWithString(string s) {
       int n = s.length();
        vector<char> minCharFrom(n);
        minCharFrom[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minCharFrom[i] = min(s[i], minCharFrom[i + 1]);
        }
        stack<char> st;
        string result = "";
        int i = 0;
        while (i < n || !st.empty()) {
            while (i < n && (st.empty() || st.top() > minCharFrom[i])) {
                st.push(s[i]);
                ++i;
            }
            result += st.top();
            st.pop();
        }
        return result; 
    }
};