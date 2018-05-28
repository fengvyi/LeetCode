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

// Segment Tree
class NumArray {
    struct SegmentTreeNode{
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int l, int r):start(l), end(r), sum(0), left(NULL), right(NULL){}
    };
    SegmentTreeNode* root;
    
    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        SegmentTreeNode* p = new SegmentTreeNode(start, end);
        if(start == end){
            p->sum = nums[start];
        }
        else{
            int mid = start + (end - start) / 2;
            p->left = buildTree(nums, start, mid);
            p->right = buildTree(nums, mid + 1, end);
            p->sum = p->left->sum + p->right->sum;
        }
        return p;
    }
    
    void update(SegmentTreeNode* p, int i, int val){
        if(p->start == i && p->end == i){
            p->sum = val;
        }
        else{
            int mid = p->start + (p->end - p->start) / 2;
            if(i <= mid) update(p->left, i, val);
            else update(p->right, i, val);
            p->sum = p->left->sum + p->right->sum;
        }
    }
    
    int sumRange(SegmentTreeNode* p, int i, int j){
        if(p->start == i && p->end == j){
            return p->sum;
        }
        int mid = p->start + (p->end - p->start) / 2;
        if(j <= mid) 
            return sumRange(p->left, i, j);
        else if(i > mid) 
            return sumRange(p->right, i, j);
        else 
            return sumRange(p->left, i, mid) + sumRange(p->right, mid + 1, j);
    }
    
public:
    NumArray(vector<int> nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
