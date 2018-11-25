// Solution 1. Brute force, O(n^2)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int i = 0; i < nums.size(); i++){
            int j = (i + 1) % n;
            while(j != i){
                if(nums[j] > nums[i]) break;
                ++j %= n;
            }
            res.push_back(j == i ? -1 : nums[j]);
        }
        return res;
    }
};

// Solution 2. Using a stack and a deque, O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(), -1);
        stack<int>s; // decreasing sequence
        deque<int>q; // Increasing sequence
        for(int i = 0; i < nums.size(); i++){
            if(q.empty() || nums[i] > q.back()) q.push_back(nums[i]);
            while(!s.empty() && nums[i] > nums[s.top()]){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            while(!q.empty() && nums[s.top()] >= q.front()) q.pop_front();
            if(!q.empty()) res[s.top()] = q.front();
            s.pop();
        }
        return res;
    }
};

// Solution 3.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        deque<vector<int>>q;
        vector<int>res(n, -1);
        for (int i = 0; i < n*2; ++i) {
            while (!q.empty() && q.back()[0] < nums[i%n]) {
                auto v = q.back();
                q.pop_back();
                res[v[1]] = nums[i%n];
            }
            q.push_back({nums[i%n], i%n});
        }
        return res;
    }
};
