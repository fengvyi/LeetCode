/**Solution 1.
 * Use one array to record the last bought stock with min price at day `i`,  
 * use another array to record the max profit at day `i`.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<int>buy(prices.size());
        vector<int>dp(prices.size());
        buy[0] = prices[0];
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++){
            buy[i] = min(buy[i - 1], prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - buy[i - 1]);
        }
        return dp[prices.size() - 1];
    }
};

/**Solution 2.
 * But you may noticed that we only concern the relationship between day `i` and day `i - 1`, 
 * therefore, we can simply use two integers to replace the two arrays, reduced space complexity to O(1).
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int buy = prices[0], profit = 0;
        for(int i = 1; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};
