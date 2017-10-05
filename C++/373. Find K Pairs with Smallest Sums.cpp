// Solution 1. MinHeap, time: O(m * n * log(m*n))
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [](pair<int, int>& p1, pair<int, int>& p2){ return p1.first + p1.second > p2.first + p2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>pq(comp);
        for(auto x: nums1) 
            for(auto y: nums2) pq.push({x, y});
        vector<pair<int, int>>res;
        while(k-- && !pq.empty()) res.push_back(pq.top()), pq.pop();
        return res;
    }
};

// Solution 2. MaxHeap, time: O(m * n * log(k)).
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [](pair<int, int>& p1, pair<int, int>& p2){ return p1.first + p1.second < p2.first + p2.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>pq(comp);
        for(auto x: nums1) 
            for(auto y: nums2){
                pq.push({x, y});
                if(pq.size() > k) pq.pop();
            }
        vector<pair<int, int>>res;
        while(!pq.empty()) res.push_back(pq.top()), pq.pop();
        return res;
    }
};
