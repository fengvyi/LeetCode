class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) m[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        auto v1 = m[word1];
        auto v2 = m[word2];
        int res = INT_MAX;
        while(!v1.empty() && !v2.empty()){
            res = min(res, abs(v1.back() - v2.back()));
            v1.back() > v2.back() ? v1.pop_back() : v2.pop_back();
        }
        return res;
    }

private:
    unordered_map<string, vector<int>>m;
};
