class NumArray {
public:
    NumArray(vector<int> nums) {
        int sum = 0;
        for(auto x: nums){
            sum += x;
            dp.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? dp[j] : dp[j] - dp[i - 1];
    }
    
private:
    vector<int>dp;
};
