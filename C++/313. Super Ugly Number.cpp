// Solution 1. 
// Time: O(n*2k)
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

// Solution 2.
// Improve from 2 inner loops to one loop, idea from this post: 
// https://discuss.leetcode.com/topic/34841/java-three-methods-23ms-36-ms-58ms-with-heap-performance-explained
// Time: O(n*k)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n);
        vector<int>p(primes.size());
        vector<int>val(primes.size());
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

// Solution 3.
// Also, I wrote the last heap version from the same post, but I think its time complexity is O(nklogk) rather than O(nlogk), 
// which is actually slower than above solution.
// Time: O(nklogk), 65ms. 
struct triple{
    int val;
    int prime;
    int p;
    triple(int x, int y, int z):val(x), prime(y), p(z){};
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n);
        dp[0] = 1;
        auto cmp = [](triple* t1, triple* t2){ return t1->val > t2->val; };
        priority_queue<triple*, vector<triple*>, decltype(cmp)>pq(cmp);
        for(int i = 0; i < primes.size(); i++) pq.push(new triple(primes[i], primes[i], 1));
        for(int i = 1; i < n; i++){
            dp[i] = pq.top()->val;
            while(pq.top()->val == dp[i]){
                triple* t = pq.top();
                pq.pop();
                pq.push(new triple(t->prime * dp[t->p], t->prime, t->p + 1));
            }
        }
        return dp[n - 1];
    }
};
