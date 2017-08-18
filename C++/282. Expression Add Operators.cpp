class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        backtrack(res, num, target, 0, 0, 0, "");
        return res;
    }
    
    void backtrack(vector<string>& res, string num, int target, int pos, long sum, long multiply, string path){
        if(pos == num.size()){
            if(target == sum) res.push_back(path);
            return;
        }
        for(int i = pos; i < num.size(); i++){
            if(i != pos && num[pos] == '0') break;
            long cur = stol(num.substr(pos, i - pos + 1));
            if(pos == 0){
                backtrack(res, num, target, i + 1, cur, cur, path + to_string(cur));
            }
            else{
                backtrack(res, num, target, i + 1, sum + cur, cur, path + "+" + to_string(cur));
                backtrack(res, num, target, i + 1, sum - cur, -cur, path + "-" + to_string(cur));
                backtrack(res, num, target, i + 1, sum - multiply + multiply * cur, multiply * cur, path + "*" + to_string(cur));    
            }
        }
    }
};
