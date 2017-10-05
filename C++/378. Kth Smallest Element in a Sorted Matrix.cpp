// Solution 1. MinHeap
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto x: matrix)
            for(auto y: x) pq.push(y);
        while(--k) pq.pop();
        return pq.top();
    }
};

// Solution 2. Multiset
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int>s;
        for(auto x: matrix)
            for(auto y: x) s.insert(y);
        auto p = s.begin();
        while(--k) p++;
        return *p;
    }
};
