// DFS + Brute Force
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

// BFS + Priority_queue
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>>g(101);
        vector<vector<int>>w(101, vector<int>(101));
        for (auto& v: flights) {
            int a = v[0];   // src
            int b = v[1];   // dst
            int c = v[2];   // weight
            g[a].push_back(b);
            w[a][b] = c;
        }
        auto comp = [](vector<int>& v1, vector<int>& v2) {
          return v1[1] > v2[1];  
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>pq(comp);
        pq.push({src, 0, K});
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int from = v[0];
            int cost = v[1];
            int stop = v[2];
            
            if (from == dst) {
                return cost;
            }
            if (stop < 0) {
                continue;
            }
            --stop;
            for (int x: g[from]) {
                pq.push({x, cost + w[from][x], stop});
            }
        }
        return -1;
    }
};
