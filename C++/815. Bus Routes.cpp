class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        unordered_map<int, vector<int>>m(501);  // Stop to Bus
        int n = routes.size();
        // Build graph Stop-to-Bus
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                m[routes[i][j]].push_back(i);
            }
        }
        vector<int>visitedBus(501);
        vector<int>visitedStop(1000001);
        // BFS
        queue<int>cur;
        queue<int>next;
        for (int& b: m[S]) {
            cur.push(b);
        }
        int count = 1;
        while (!cur.empty()) {
            int bus = cur.front();
            cur.pop();
            visitedBus[bus] = 1;
            for (int& s: routes[bus]) {
                if (s == T) {
                    return count;
                }
                if (visitedStop[s]) {
                   continue;
                }
                visitedStop[s] = 1;
                for (int& b: m[s]) {
                    if (!visitedBus[b]) {
                        next.push(b);
                    }
                }
            }
            
            if (cur.empty()) {
                ++count;
                swap(cur, next);
            }
        }
        return -1;
    }
};
