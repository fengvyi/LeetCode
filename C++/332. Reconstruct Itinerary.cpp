class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>>m;
        vector<string>res;
        for(auto x: tickets) m[x.first].push(x.second);
        DFS("JFK", res, m);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void DFS(string cur, vector<string>& res, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& m){
        while(!m[cur].empty()){
            string s = m[cur].top();
            m[cur].pop();
            DFS(s, res, m);
        }
        res.push_back(cur);
    }
};
