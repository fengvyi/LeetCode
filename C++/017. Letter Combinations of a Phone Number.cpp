class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return res;
        string s = "";
        unordered_map<char,vector<int>>m({{'2', {'a','b','c'}},
                                          {'3', {'d','e','f'}},
                                          {'4', {'g','h','i'}},
                                          {'5', {'j','k','l'}},
                                          {'6', {'m','n','o'}},
                                          {'7', {'p','q','r','s'}},
                                          {'8', {'t','u','v'}},
                                          {'9', {'w','x','y','z'}}});
        DFS(m, digits, 0, res, s);
        return res;
    }
    
    void DFS(unordered_map<char,vector<int>>& m, string& digits, int l, vector<string>& res, string& s){
        if(l == digits.size()){
            res.push_back(s);
            return;
        }
        for(int i = 0; i < m[digits[l]].size(); i++){
            s.push_back(m[digits[l]][i]);
            DFS(m, digits, l+1, res, s);
            s.pop_back();
        }
        return;
    } 
};

// Update
class Solution {
public:
    vector<string> letterCombinations(string s) {
        vector<string>res;
        if(s.empty()) return res;
        vector<string>v({"", "", "abc", "def", "ghi","jkl","mno","pqrs", "tuv", "wxyz"});
        DFS(s, res, 0, "", v);
        return res;
    }
    
private:
    void DFS(string s, vector<string>& res, int pos, string path, vector<string>& v){
        if(pos == s.size()){
            res.push_back(path);
            return;
        }
        for(auto c: v[s[pos] - '0']){
            path.push_back(c);
            DFS(s, res, pos + 1, path, v);
            path.pop_back();
        }
    }
};
