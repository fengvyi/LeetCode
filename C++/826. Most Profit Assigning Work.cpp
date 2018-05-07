class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0;
        vector<vector<int>>v;
        for(int i = 0; i < difficulty.size(); i++) v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end(), [](vector<int>& v1, vector<int>& v2){ return v1[0] < v2[0]; });
        int maxProfit = 0;
        for(auto& x: v){
            maxProfit = max(maxProfit, x[1]);
            x[1] = maxProfit;
        }
        for(auto& x: worker){
            int pos = upper_bound(v.begin(), v.end(), x, [](int v1, vector<int>& v2){ return v1 < v2[0]; }) - v.begin() - 1;
            if(pos >= 0) res += v[pos][1];
        }
        return res;
    }
};
