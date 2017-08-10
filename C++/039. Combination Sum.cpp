class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>comb;
        backtrack(res, candidates, 0, 0, target, comb);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int pos, int sum, int target, vector<int>& comb){
        if(sum > target || pos == candidates.size()) return;
        if(sum == target){
            res.push_back(comb);
            return;
        }
        backtrack(res, candidates, pos + 1, sum, target, comb);
        comb.push_back(candidates[pos]);
        backtrack(res, candidates, pos, sum + candidates[pos], target, comb);
        comb.pop_back();
    }
};
