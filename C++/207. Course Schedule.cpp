class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto p: prerequisites) graph[p.second].push_back(p.first);
        vector<int>indegree(numCourses);
        for(auto x: graph) for(auto y: x) indegree[y]++;
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++) if(indegree[j] == 0) break;
            if(j == numCourses) return false;
            for(auto x: graph[j]) indegree[x]--;
            indegree[j] = -1;
        }
        return true;
    }
};
