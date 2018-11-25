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

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double>res;
        unordered_map<string, vector<string>>g;
        unordered_map<string, unordered_map<string, double>>w;
        // Build graph
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i].first;
            string b = equations[i].second;
            g[a].push_back(b);
            g[b].push_back(a);
            w[a][b] = values[i];
            w[b][a] = 1/values[i];
        }
        
        for (auto& q: queries) {
            string from = q.first;
            string dest = q.second;
            
            if (!g.count(from) || !g.count(dest)) {
                res.push_back(-1);
                continue;
            }
            
            // BFS
            unordered_set<string>visited;
            queue<pair<string, double>>cur, next;
            cur.push({from, 1});
            bool found = false;
            while(!cur.empty()) {
                auto node = cur.front();
                cur.pop();
                
                string s = node.first;
                double val = node.second;
                
                visited.insert(s);
                
                if (s == dest) {
                    res.push_back(val);
                    found = true;
                    break;
                }
                
                for (auto& x: g[s]) {
                    if (!visited.count(x)) {
                        next.push({x, val * w[s][x]});
                    }
                }
                if (cur.empty()) {
                    swap(cur, next);
                }
            }
            if (!found) {
                res.push_back(-1);
            }
        }
        return res;
    }
};
