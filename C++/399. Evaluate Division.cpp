class Solution {
private:
    unordered_map<string, unordered_map<string, double>>weight;
    unordered_map<string, vector<string>>graph;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double>res;
        for(int i = 0; i < values.size(); i++){
            auto p = equations[i];
            weight[p.first][p.second] = values[i];
            weight[p.second][p.first] = 1 / values[i];
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        for(int i = 0; i < queries.size(); i++){
            unordered_set<string>visited;
            deque<pair<string, double>>cur;
            deque<pair<string, double>>next;
            cur.push_back({queries[i].first, 1});
            double d = -1.0;
            if(graph.count(queries[i].first))
                while(!cur.empty()){
                    auto node = cur.front();
                    cur.pop_front();
                    visited.insert(node.first);
                    if(node.first == queries[i].second){
                        d = node.second;
                        break;
                    }
                    for(auto neigh: graph[node.first])
                        if(visited.count(neigh) == 0)
                            next.push_back({neigh, node.second * weight[node.first][neigh]});
                    if(cur.empty()) swap(cur, next);
                }
            res.push_back(d);
        }
        return res;
    }
};
