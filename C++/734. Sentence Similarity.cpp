class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        unordered_map<string, unordered_set<string>>m;
        for(auto x: pairs){
            m[x.first].insert(x.second);
            m[x.second].insert(x.first);
        }
        for(int i = 0; i < words1.size(); i++)
            if(words1[i] != words2[i] && !m[words1[i]].count(words2[i])) return false;
        return true;
    }
};
