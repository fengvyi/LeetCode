class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>res;
        
        for (const string& s: emails) {
            string e = filter(s);
            res.insert(e);
        }
        
        return res.size();
    }
    
    string filter(const string& email) {
        string res;
        int i = 0, n = email.size();
        bool ignore = false;
        for (; i < n; ++i) {
            if (email[i] == '@') {
                break;
            } else if (ignore || email[i] == '.') {
                continue;
            } else if (email[i] == '+') {
                ignore = true;
            }
            res.push_back(email[i]);
        }
        
        for (; i < n; ++i) {
            res.push_back(email[i]);
        }
        return res;
    }
};
