// Solution 1. Brute force, 153ms.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        backtrack(res, nums, 0, vector<int>());
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int pos, vector<int>comb){
        if(pos >= nums.size()){
            for(auto x: res) if(isEqual(x, comb)) return;
            res.push_back(comb);
            return;
        }
        backtrack(res, nums, pos + 1, comb);
        comb.push_back(nums[pos]);
        backtrack(res, nums, pos + 1, comb);
    }
    
    bool isEqual(vector<int>& v1, vector<int>& v2){
        if(v1.size() != v2.size()) return false;
        unordered_map<int, int>m;
        for(auto x: v1) m[x]++;
        for(auto x: v2) if(--m[x] < 0) return false;
        return true;
    }
};

// Solution 2. Sort first, 9ms.
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        vector<int>comb;
        backtrack(res, nums, 0, comb);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int pos, vector<int>& comb){
        res.push_back(comb);
        for(int i = pos; i < nums.size(); i++){
            if(i == pos || nums[i] != nums[i - 1]){
                comb.push_back(nums[i]);
                backtrack(res, nums, i + 1, comb);
                comb.pop_back();
            }
        }
    }
};
