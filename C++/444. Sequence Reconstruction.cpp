class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        unordered_map<int, unordered_set<int>>graph;
        vector<int>indegree(n + 1, -1);
        for(auto v: seqs)
            for(int i = 0; i < v.size(); i++){
                if(v[i] > n || v[i] < 0) return false;
                if(indegree[v[i]] == -1) indegree[v[i]] = 0;
                if(i + 1 < v.size() && graph[v[i]].insert(v[i + 1]).second)
                    if(v[i + 1] > n || v[i + 1] < 0) return false;
                    else indegree[v[i + 1]] += indegree[v[i + 1]] < 0 ? 2 : 1;
            }
        for(int i = 0; i < n - 1; i++)
            if(indegree[org[i]] || !indegree[org[i + 1]]) return false;
            else for(auto x: graph[org[i]]) indegree[x]--;
        return indegree[org.back()] == 0;
    }
};
