class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n);
        dp[0] = 1;
        vector<int>p(primes.size());
        for(int i = 1; i < n; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < p.size(); j++) dp[i] = min(dp[i], dp[p[j]] * primes[j]);
            for(int k = 0; k < p.size(); k++) if(dp[p[k]] * primes[k] == dp[i]) p[k]++;
        }
        return dp[n - 1];
    }
};
