// Solution 1. Brute force, 196ms.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string>res;
        int minMove = INT_MAX;
        backtrack(res, s, 0, 0, minMove);
        return res;
    }
    
    void backtrack(vector<string>& res, string s, int pos, int move, int& minMove){
        if(pos > s.size() || move > minMove) return;
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
    
    bool isValid(string& s){
        int sum = 0;
        for(auto c: s){
            if(c == '(') sum++;
            else if(c == ')') sum--;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
};

// Solution 2. BFS, 63ms.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>visited;
        vector<string>res;
        deque<string>cur;
        deque<string>next;
        cur.push_back(s);
        while(!cur.empty()){
            s = cur.front();
            cur.pop_front();
            if(isValid(s)){
                res.push_back(s);
                continue;
            }
            for(int i = 0; i < s.size(); i++){
                if(s[i] != '(' && s[i] != ')') continue;
                string tmp = s.substr(0, i) + s.substr(i + 1);
                if(visited.count(tmp) == 0){
                    next.push_back(tmp);
                    visited.insert(tmp);
                }
            }
            if(cur.empty() && res.size() == 0) swap(cur, next);
        }
        return res;
    }
    
    bool isValid(string& s){
        int sum = 0;
        for(auto c: s){
            if(c == '(') sum++;
            else if(c == ')') sum--;
            if(sum < 0) return false;
        }
        return sum == 0;
    }
};
