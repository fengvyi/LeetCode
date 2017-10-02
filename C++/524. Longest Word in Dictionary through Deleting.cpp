class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int>p(d.size());
        int maxlen = 0;
        string res = "";
        for(auto c: s)
            for(int i = 0; i < d.size(); i++){
                if(p[i] == d[i].size()) continue;
                if(c == d[i][p[i]]) p[i]++;
            }
        for(int i = 0; i < p.size(); i++){
            if(p[i] != d[i].size()) continue;
            if(p[i] == maxlen && d[i].compare(res) < 0) res = d[i];
            if(p[i] > maxlen){
                maxlen = p[i];
                res = d[i];
            }
        }
        return res;
    }
};
