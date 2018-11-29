class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for (auto& s: words) {
            if (isValid(s, pattern)) {
                res.push_back(s);
            }
        }
        return res;
    }
    
    bool isValid(string& a, string& b) {
        unordered_map<char, char>m, t;
        int n = a.size(), l = b.size();
        if (n != l) {
            return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (m.count(a[i]) || t.count(b[i])) {
                if (m[a[i]] == b[i] && t[b[i]] == a[i]) {
                    continue;
                } else {
                    return false;
                }
            }
            m[a[i]] = b[i];
            t[b[i]] = a[i];
        }
        return true;
    }
};

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for (auto& s: words) {
            if (normalize(s) == normalize(pattern)) {
                res.push_back(s);
            }
        }
        return res;
    }
    
    string normalize(string& s) {
        unordered_map<char, char>m;
        string res;
        char c = 'a';
        for (auto& x: s) {
            if (!m.count(x)) {
                m[x] = c++;
            }
        }
        for (auto& x: s) {
            res.push_back(m[x]);
        }
        return res;
    }
};
