class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>path;
        DFS(res, nums, 0, target, 0, 0, path);
        return res;
    }
    
    void DFS(vector<vector<int>>& res, vector<int>& nums, int pos, int target, int count, int sum, vector<int>& path){
        if(count == 4){
            if(sum == target) res.push_back(path);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            path.push_back(nums[pos]);
            DFS(res, nums, pos + 1, target, count + 1, sum + nums[pos], path);
            path.pop_back();
        }
    }
};
