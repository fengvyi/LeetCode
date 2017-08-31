class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(auto s: strs) res = match(res, s);
        return res;
    }
    
    string match(const string& pre, const string& s){
        int i = 0, len = min(pre.size(), s.size());
        for(; i < len; i++) if(s[i] != pre[i]) break;
        return pre.substr(0, i);
    }
};
