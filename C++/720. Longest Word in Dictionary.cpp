class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        unordered_map<int, unordered_set<string>>m;
        for(auto s: words) m[s.size()].insert(s);
        for(auto s: words){
            int i = 1;
            while(i < s.size() && m[i].count(s.substr(0, i))) i++;
            if(i == s.size() && s.size() >= res.size()) res = s.size() > res.size() ? s : min(s, res);
        }
        return res;
    }
};
