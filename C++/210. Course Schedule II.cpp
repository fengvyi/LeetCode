class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>res;
        vector<int>indegree(numCourses);
        vector<vector<int>>graph(numCourses);
        for(auto p: prerequisites){
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++) if(indegree[j] == 0) break;
            if(j == numCourses) return vector<int>();
            indegree[j] = -1;
            for(auto x: graph[j]) indegree[x]--;
            res.push_back(j);
        }
        return res;
    }
};
