class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>res;
        for(int i = 0; i < strings.size(); i++){
            if(strings[i].empty()) continue;
            vector<string>vec({strings[i]});
            for(int j = i + 1; j < strings.size(); j++)
                if(isSameGroup(strings[i], strings[j])){
                    vec.push_back(strings[j]);
                    strings[j] = "";
                }
            res.push_back(vec);
        }
        return res;
    }
    
    bool isSameGroup(string a, string b){
        if(a.empty() || b.empty() || a.size() != b.size()) return false;
        int d = b[0] - a[0];
        d = d < 0 ? d + 26 : d;
        for(int i = 0; i < a.size(); i++)
            if(b[i] - 'a' != (a[i] - 'a' + d) % 26) return false;
        return true;
    }
};

// Update 26/11/18
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;
        for (auto& s: strings) {
            m[helper(s)].push_back(s);
        }
        for (auto& v: m) {
            res.push_back(v.second);
        }
        return res;
    }
    
    string helper(string s) {
        if (s.size() <= 1) {
            return "a";
        }
        int diff = s[0] - 'a';
        string res;
        for (auto c: s) {
            if (c - diff < 'a') {
                c = c + (26 - diff);
            } else {
                c = c - diff;
            }
            res.push_back(c);
        }
        return res;
    }
};
