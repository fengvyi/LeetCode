class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int minPrice = INT_MAX;
        vector<vector<vector<int>>>g(n);
        for(auto v: flights) g[v[0]].push_back({v[1], v[2]});
        dfs(g, src, dst, K, 0, minPrice);
        return minPrice == INT_MAX ? -1 : minPrice;
    }
    
    void dfs(vector<vector<vector<int>>>& g, int cur, int dst, int K, int price, int& minPrice){
        if(cur == dst){
            minPrice = min(minPrice, price);
            return;
        }
        if(K == -1 || price >= minPrice) return;
        for(auto v: g[cur]) dfs(g, v[0], dst, K - 1, price + v[1], minPrice);
    }
};
