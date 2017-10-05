class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);
    }
    
    vector<string> helper(int m, int n){
        if(m == 0) return {""};
        if(m == 1) return {"0", "1", "8"};
        vector<string>v = helper(m - 2, n);
        vector<string>res;
        for(auto x: v){
            if(m != n) res.push_back('0' + x + '0');
            res.push_back('6' + x + '9');
            res.push_back('9' + x + '6');
            res.push_back('1' + x + '1');
            res.push_back('8' + x + '8');
        }
        return res;
    }
};
