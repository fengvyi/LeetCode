class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& p1, pair<int, int>& p2){
            return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
        });
        vector<int>dp;
        for(auto x: envelopes){
            int pos = lower_bound(dp.begin(), dp.end(), x.second) - dp.begin();
            if(pos == dp.size()) dp.push_back(x.second);
            else dp[pos] = x.second;
        }
        return dp.size();
    }
};
