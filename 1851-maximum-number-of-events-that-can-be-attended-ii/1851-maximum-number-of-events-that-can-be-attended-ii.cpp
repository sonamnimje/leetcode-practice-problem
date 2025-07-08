class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort events by start time
        int n = events.size();

        // Build list of start times for binary search
        vector<int> startTimes;
        for (auto &e : events) startTimes.push_back(e[0]);

        // dp[i][j] = max value by choosing at most i events from first j events
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Option 1: skip event j-1
                dp[i][j] = dp[i][j - 1];

                // Option 2: take event j-1
                int prev = lower_bound(startTimes.begin(), startTimes.end(), events[j - 1][0]) - startTimes.begin();
                // Find last event that ends before events[j - 1][0]
                int l = 0, r = j - 1, idx = 0;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (events[m][1] < events[j - 1][0]) l = m + 1;
                    else r = m;
                }
                if (events[l][1] < events[j - 1][0]) idx = l + 1;
                else idx = l;
                dp[i][j] = max(dp[i][j], dp[i - 1][idx] + events[j - 1][2]);
            }
        }

        return dp[k][n];
    }
};
