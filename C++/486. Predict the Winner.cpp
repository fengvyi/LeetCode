class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int>score(2);
        return solve(nums, score, 0, 0, nums.size() - 1);
    }
    
    bool solve(vector<int>& nums, vector<int>& score, int player, int l, int r) {
        if (l >= r) {
            return score[0] >= score[1];
        }
        
        if (player == 0) {
            // Pick left
            score[0] += nums[l];
            if (solve(nums, score, player ^ 1, l + 1, r)) {
                score[0] -= nums[l];
                return true;
            }
            score[0] -= nums[l];
            // Pick right
            score[0] += nums[r];
            if (solve(nums, score, player ^ 1, l, r - 1)) {
                score[0] -= nums[r];
                return true;
            }
            score[0] -= nums[r];
        } else {
            // Pick left
            score[1] += nums[l];
            if (!solve(nums, score, player ^ 1, l + 1, r)) {
                score[1] -= nums[l];
                return false;
            }
            score[1] -= nums[l];
            // Pick right
            score[1] += nums[r];
            if (!solve(nums, score, player ^ 1, l, r - 1)) {
                score[1] -= nums[r];
                return false;
            }
            score[1] -= nums[r];
        }
        return player;
    }
};
