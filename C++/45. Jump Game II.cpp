class Solution {
public:
    int jump(vector<int>& nums) {
        int minJump = nums.size();
        DFS(nums, 0, 0, minJump);
        return minJump;
    }
    
    void DFS(vector<int>& nums, int pos, int jump, int& minJump){
        if(pos == nums.size() - 1){
            minJump = min(minJump, jump);
            return;
        }
        int next = pos + 1, maxlen = 1 + nums[pos + 1];
        for(int i = 1; i <= nums[pos] && pos + i < nums.size(); i++)
            if(i + nums[pos + i] > maxlen || pos + i == nums.size() - 1) next = pos + i, maxlen = i + nums[next];
        DFS(nums, next, jump + 1, minJump);
    }
};
