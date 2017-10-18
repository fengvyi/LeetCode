class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int>res;
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int x = a * nums[i] * nums[i] + b * nums[i] + c;
            int y = a * nums[j] * nums[j] + b * nums[j] + c;
            if(a * x > a * y){
                i++;
                res.push_back(x);
            }
            else{
                j--;
                res.push_back(y);
            }
        }
        if(a > 0 || a == 0 && b > 0) reverse(res.begin(), res.end());
        return res;
    }
};
