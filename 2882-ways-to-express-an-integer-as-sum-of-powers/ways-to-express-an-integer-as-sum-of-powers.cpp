class Solution {
public:
    int numberOfWays(int n, int x) 
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1; 
        for (int i = 1; pow(i, x) <= n; i++) 
        {
            int p = (int)pow(i, x);
            for (int sum = n; sum >= p; sum--) 
            {
                dp[sum] = (dp[sum] + dp[sum - p]) % MOD;
            }
        }
        return dp[n];
    }
};