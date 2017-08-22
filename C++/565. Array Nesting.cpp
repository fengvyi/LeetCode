class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxDepth = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == -1) continue;
            DFS(nums, i, 0, maxDepth);
        }
        return maxDepth;
    }
    
    void DFS(vector<int>& nums, int num, int depth, int& maxDepth){
        if(nums[num] == -1){
            maxDepth = max(maxDepth, depth);
            return;
        }
        int next = nums[num];
        nums[num] = -1;
        DFS(nums, next, depth + 1, maxDepth);
    }
};
