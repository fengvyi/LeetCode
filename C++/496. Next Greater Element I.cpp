class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int>m;
        stack<int>s;
        for(auto x: nums){
            while(!s.empty() && s.top() < x){
                m[s.top()] = x;
                s.pop();
            }
            s.push(x);
        }
        for(auto& x: findNums) x = m.count(x) ? m[x] : -1;
        return findNums;
    }
};
