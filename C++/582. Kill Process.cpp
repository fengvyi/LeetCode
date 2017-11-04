class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int>res;
        unordered_map<int, vector<int>>g;
        for(int i = 0; i < pid.size(); i++) g[ppid[i]].push_back(pid[i]);
        // BFS
        deque<int>q;
        q.push_back(kill);
        while(!q.empty()){
            auto p = q.front();
            q.pop_front();
            for(auto child: g[p]) q.push_back(child);
            res.push_back(p);
        }
        // DFS
        // DFS(g, kill, res);
        return res;
    }
    
    void DFS(unordered_map<int, vector<int>>& g, int kill, vector<int>& res){
        res.push_back(kill);
        for(auto child: g[kill]) DFS(g, child, res);
    }
};
