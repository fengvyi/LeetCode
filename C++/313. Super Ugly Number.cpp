class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n);
        dp[0] = 1;
        vector<int>p(primes.size());
        for(int i = 1; i < n; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < p.size(); j++) dp[i] = min(dp[i], dp[p[j]] * primes[j]);
            for(int j = 0; j < p.size(); j++) if(dp[p[j]] * primes[j] == dp[i]) p[j]++;
        }
        return dp[n - 1];
    }
};

// Trade-off space for time, beats 96.63%.
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n);
        vector<int>p(primes.size());
        vector<int>val(primes.size(), 1);
        int next = 1;
        for(int i = 0; i < n; i++){
            dp[i] = next;
            next = INT_MAX;
            for(int j = 0; j < val.size(); j++){
                if(dp[i] >= val[j]) val[j] = dp[p[j]++] * primes[j];
                next = min(next, val[j]);
            }
        }
        return dp[n - 1];
    }
};
