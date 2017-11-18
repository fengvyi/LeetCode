class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>>res(r, vector<int>(c));
        int row = 0, col = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                res[i][j] = nums[row][col++];
                if(col == n) col = 0, row++;
            }
        return res;
    }
};

// Or
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if(m * n != r * c) return nums;
        vector<vector<int>>res(r, vector<int>(c));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                res[i][j] = nums[(i * c + j) / n][(i * c + j) % n];
        return res;
    }
};
