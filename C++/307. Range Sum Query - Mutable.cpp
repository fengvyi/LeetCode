// Yes, it passed the judge.
class NumArray {
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    void update(int i, int val) {
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int a = i; a <= j; a++) sum += nums[a];
        return sum;
    }
    
private:
    vector<int> nums;
};
