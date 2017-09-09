class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(s.empty()){
            if(p.empty()) return true;
            if(p[1] != '*') return false;
            return isMatch(s, p.substr(2));
        }
        if(p[1] == '*'){
            if(p[0] != '.' && s[0] != p[0]) return isMatch(s, p.substr(2));
            return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
        }
        if(p[0] != '.' && s[0] != p[0]) return false;
        return isMatch(s.substr(1), p.substr(1));
    }
};
