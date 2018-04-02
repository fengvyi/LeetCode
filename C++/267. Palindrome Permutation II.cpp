class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int>v(128);
        unordered_set<char>m;
        int odd = 0;
        for(auto c: s){
            ++v[c] % 2 ? odd++ : odd--;
            m.insert(c);
        }
        if(odd > 1) return {};
        vector<string> res;
        dfs(v, res, "", "", s.size(), m);
        return res;
    }
    
    void dfs(vector<int>& v, vector<string>& res, string a, string b, int remain, unordered_set<char>& m){
        if(remain == 0){
            reverse(b.begin(), b.end());
            res.push_back(a + b);
        }
        else if(remain == 1){
            for(auto i: m) if(v[i]) a.push_back(i);
            dfs(v, res, a, b, 0, m);
        }
        else{
            for(auto i: m){
                if(v[i] >= 2){
                    a.push_back(i);
                    b.push_back(i);
                    v[i] -= 2;
                    dfs(v, res, a, b, remain - 2, m);
                    v[i] += 2;
                    a.pop_back();
                    b.pop_back();
                }
            }
        }
    }
};
