class Solution {
public:
    string crackSafe(int n, int k) {
        int target = pow(k, n);
        string res;
        for (int i = 0; i < n; ++i) {
            res += '0';
        }
        string cur = res;
        unordered_set<string>visited;
        dfs(res, target, visited, n, k, cur);
        return res;
    }
    
    bool dfs(string& res, int& target, unordered_set<string>& visited, int n, int k, string cur) {
        if (visited.count(cur)) {
            return false;
        }
        
        visited.insert(cur);
        
        if (visited.size() == target) {
            return true;
        }
        
        string next = cur.substr(1);
        
        for (int i = 0; i < k; ++i) {
            next.push_back('0' + i);
            if (!visited.count(next)) {
                res.push_back('0' + i);
                if (dfs(res, target, visited, n, k, next)) {
                    return true;
                }
                res.pop_back();
            }
            next.pop_back();
        }
        visited.erase(cur);
        return false;
    }
};
