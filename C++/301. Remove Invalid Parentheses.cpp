class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        int minMove = INT_MAX;
        backtrack(res, s, 0, 0, minMove);
        return res;
    }
    
    void backtrack(vector<string>& res, string s, int pos, int move, int& minMove){
        if(pos > s.size()) return;
        if(isValid(s)){
            if(move < minMove) res.clear(), res.push_back(s), minMove = move;
            else if(move == minMove && find(res.begin(), res.end(), s) == res.end()) res.push_back(s);
            return;
        }
        while(pos < s.size() && s[pos] != '(' && s[pos] != ')') pos++;
        if(pos >= s.size()) return;
        backtrack(res, s.substr(0, pos) + s.substr(pos + 1), pos, move + 1, minMove);
        backtrack(res, s, pos + 1, move, minMove);
    }
    
    bool isValid(string s){
        int sum = 0;
        for(auto c: s){
            if(c == '(') sum++;
            else if(c == ')') sum--;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
};
