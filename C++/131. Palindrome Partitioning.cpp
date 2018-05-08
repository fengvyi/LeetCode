class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        dfs(s, 0, v, res);
        return res;
    }
    
    void dfs(string s, int pos, vector<string>& v, vector<vector<string>>& res){
        if(pos >= s.size()){
            res.push_back(v);
            return;
        }
        
        for(int i = pos; i < s.size(); i++){
            int l = pos, r = i;
            bool b = true;
            while(l < r && b) if(s[l++] != s[r--]) b = false;
            if(b){
                v.push_back(s.substr(pos, i - pos + 1));
                dfs(s, i + 1, v, res);
                v.pop_back();
            }
        }
    }
};
