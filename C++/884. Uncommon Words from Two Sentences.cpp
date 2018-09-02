class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int>m;
        vector<string>res;
        stringstream ss(A + " " + B);
        string t;
        while(ss>>t) m[t]++;
        for(auto& x: m) if(x.second == 1) res.push_back(x.first);
        return res;
    }
};
