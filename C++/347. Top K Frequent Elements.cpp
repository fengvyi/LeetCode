// Solution 1. MaxHeap, O(nlogn).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto x: nums) m[x]++;
        priority_queue<pair<int, int>>pq;
        for(auto p: m) pq.push({p.second, p.first});
        vector<int>res;
        while(k--) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};

// O(nlog(n - k)).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto x: nums) m[x]++;
        priority_queue<pair<int, int>>pq;
        vector<int>res;
        for(auto p: m){
            pq.push({p.second, p.first});
            if(pq.size() > m.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

// Solution 2. MinHeap, O(nlogk).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto x: nums) m[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(auto p: m){
            pq.push({p.second, p.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int>res;
        while(k--) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};

// Solution 3. Bucket Sort, O(n).
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto x: nums) m[x]++;
        vector<int>res;
        vector<vector<int>>bucket(nums.size() + 1);
        for(auto p: m) bucket[p.second].push_back(p.first);
        for(int i = bucket.size() - 1; res.size() < k; i--)
            for(auto j: bucket[i]) res.push_back(j);
        return res;
    }
};
