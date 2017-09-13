// My solution.
class Solution {
public:
    int numDecodings(string s) {
        /** dp[i] = 
         * value                            Example
         * 0                                00, 30, 80 - invalid ending
         * dp[i-2]                          10, 20     - valid ending with 0
         * dp[i-2]                          08, 09     - s[i - 1] == '0'      
         * dp[i-1] + dp[i-2]                11, 16     - valid ending
         * dp[i-1]                          32, 56     - large ending, decrease i by 1
         */
        if(s.size() == 0 || s[0] == '0') return 0;
        vector<int>dp(s.size());
        dp[0] = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0'){
                if(s[i - 1] == '0' || s[i - 1] - '0' > 2) return 0;
                dp[i] = (i==1) ? dp[0] : dp[i - 2];
            }
            else if(s[i - 1] == '0') dp[i] = dp[i - 2];
            else if(stoi(s.substr(i - 1, 2)) <= 26) dp[i] = (i==1) ? dp[0] + 1 : dp[i - 1] + dp[i - 2];
            else dp[i] = dp[i - 1];
        }
        return dp[s.size()-1];
    }
};

// Solution from here: https://discuss.leetcode.com/topic/7025/a-concise-dp-solution
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.front() == '0') return 0;
        int p1 = 1, p2 = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0') p1 = 0;
            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7'){
                p1 = p1 + p2;
                p2 = p1 - p2;
            }
            else p2 = p1;
        }
        return p1;
    }
};
