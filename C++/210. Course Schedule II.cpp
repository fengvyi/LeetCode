class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>res;
        for(auto p: prerequisites) graph[p.second].push_back(p.first);
        vector<int>indegree(numCourses);
        for(auto x: graph) for(auto y: x) indegree[y]++;
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++) if(indegree[j] == 0) break;
            if(j == numCourses) return vector<int>();
            for(auto x: graph[j]) indegree[x]--;
            res.push_back(j);
            indegree[j] = -1;
        }
        return res;
    }
};
