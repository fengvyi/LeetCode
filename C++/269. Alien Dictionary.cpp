class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) return 0;
        unordered_map<char, unordered_set<char>>graph;
        unordered_map<char, int>degree;
        for(auto x: words) for(auto c: x) degree[c] = 0;
        for(int i = 0; i < words.size() - 1; i++){
            string a = words[i], b = words[i + 1];
            for(int j = 0; j < min(a.size(), b.size()); j++){
                if(a[j] == b[j]) continue;
                if(!graph[a[j]].count(b[j])){
                    graph[a[j]].insert(b[j]);
                    degree[b[j]]++;
                }
                break;
            }
        }
        string res = "";
        while(true){
            char c = '#';
            for(auto x: degree)
                if(x.second == 0) c = x.first;
            if(c == '#') break;
            degree[c] = -1;
            for(auto neigh: graph[c])
                degree[neigh]--;
            res += c;
        }
        if(res.size() != degree.size()) return "";
        return res;
    }
};
