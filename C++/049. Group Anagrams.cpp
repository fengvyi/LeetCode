class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;
        for(auto s: strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }
        for(auto x: m) res.push_back(x.second);
        return res;
    }
};

// Implement an O(n) sort() function myself.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;
        for(auto s: strs){
            string tmp = s;
            sortStr(tmp);
            m[tmp].push_back(s);
        }
        for(auto x: m) res.push_back(x.second);
        return res;
    }
    
    void sortStr(string& s){
        unordered_map<char, int>m;
        for(auto c: s) m[c]++;
        string res = "";
        for(int i = 0; i < 26; i++){
            while(m['a' + i]-- > 0) res.push_back('a' + i);
        }
        s = res;
    }
};
