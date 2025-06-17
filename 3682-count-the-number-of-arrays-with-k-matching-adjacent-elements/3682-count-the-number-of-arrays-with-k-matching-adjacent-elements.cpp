class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2); // Fermat's inverse
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n); // up to n
        long long ways = comb(n - 1, k);
        ways = ways * m % MOD;
        ways = ways * modPow(m - 1, n - 1 - k) % MOD;
        return ways;
    }
};
