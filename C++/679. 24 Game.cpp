class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        unordered_set<string>res;
        string ops = "+-*/";
        dfs(nums, "", ops, res);
        for (auto& x: res) {
            auto v = getResult(x);
            if (!v.empty() && abs(v.back() - 24) < 0.0001) {
                return true;
            }
        }
        return false;
    }
    
    // Generate all possible permutations
    void dfs(vector<int>& nums, string s, string& ops, unordered_set<string>& res) {
        for (int& x: nums) {
            if (x == 0) {
                continue;
            }
            int tmp = x;
            s.push_back(x + '0');
            x = 0;
            
            if (s.size() == 7) {
                res.insert(s);
                s.pop_back();
                x = tmp;
                return;
            }
            
            for (auto c: ops) {
                s.push_back(c);
                dfs(nums, s, ops, res);
                s.pop_back();
            }
            s.pop_back();
            x = tmp;
        }
    }
    
    // Generate all possible results from string 's'
    vector<double> getResult(string s) {
        int n = s.size();
        if (n == 1) {
            return {s[0] - '0'};
        }
        vector<double>res;
        for (int i = 1; i <= n - 2; i += 2) {
            vector<double> l = getResult(s.substr(0, i));
            vector<double> r = getResult(s.substr(i + 1));
            char op = s[i];
            
            for (auto& x: l) {
                for (auto& y: r) {
                    if (op == '/' && !y) {
                        continue;
                    }
                    double val = helper(op, x, y);
                    res.push_back(val);
                    if (s.size() == 7 && abs(val - 24) < 0.0001) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
    
    double helper(char op, double a, double b) {
        if (op == '+') {
            a += b;
        } else if (op == '-') {
            a -= b;
        } else if (op == '*') {
            a *= b;
        } else {
            a /= b;
        }
        return a;
    }
};
