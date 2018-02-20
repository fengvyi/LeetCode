class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n);
        color[0] = 1;
        for(int i = 0; i < n; i++){
            auto neigh = graph[i];
            if(!color[i]) for(auto j: neigh) if(color[j]){ color[i] = -color[j]; break; }   // If un-colored, pick a color by neighbor 
            if(!color[i]) color[i] = 1;  // Empty neighbor or no colored neighbor, colored 1 as default
            for(auto j: neigh)
                if(!color[j]) color[j] = -color[i];
                else if(color[i] != -color[j]) return false;
        }
        return true;
    }
};
