class RLEIterator {
public:
    RLEIterator(vector<int> A) {
        for (auto x: A) {
            nums.push_back(x);
        }
    }
    
    int next(int n) {
        while (!nums.empty() && nums.front() < n ) {
            n -= nums.front();
            nums.pop_front();
            nums.pop_front();
        }
        if (nums.empty()) {
            return -1;
        }
        int count = nums.front();
        nums.pop_front();
        int res = nums.front();
        count -= n;
        if (count == 0) {a
            nums.pop_front();
        } else {
            nums.push_front(count);
        }
        return res;
    }
    
private:
    deque<int>nums;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */
