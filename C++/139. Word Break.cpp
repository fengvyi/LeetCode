class Solution {
private:
    unordered_map<string, int>m;
    unordered_map<string, bool>dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto x: wordDict) m[x]++;
        return DFS(s);
    }
    
    bool DFS(string s){
        if(dp.count(s)) return dp[s];
        if(s.empty()) return true;
        bool found = false;
        for(int i = 0; i < s.size(); i++){
            string str = s.substr(0, i + 1);
            if(m.count(str)) found |= DFS(s.substr(i + 1));
        }
        dp[s] = found;
        return found;
    }
};
