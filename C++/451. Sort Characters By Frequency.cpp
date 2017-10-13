class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int>m;
        for(auto c: s) m[c]++;
        auto comp = [](pair<int, char>& a, pair<int, char>& b){ return a.first < b.first; };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(comp)>pq(comp);
        for(auto x: m) pq.push({x.second, x.first});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            while(p.first--) res += p.second;
        }
        return res;
    }
};
