class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>res;
        unordered_map<string, int>m;
        auto comp = [](pair<int, string>& a, pair<int, string>& b){ return a.first == b.first ? a.second < b.second : a.first > b.first; };
        priority_queue<pair<int, string>, vector<pair<int, string> >, decltype(comp)>pq(comp);
        for(auto x: words) m[x]++;
        for(auto x: m){
            pq.push({x.second, x.first});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) res.push_back(pq.top().second), pq.pop();
        reverse(res.begin(), res.end());
        return res;
    }
};
