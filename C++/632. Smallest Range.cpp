class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>res(2);
        auto comp = [](vector<int>& a, vector<int>& b){ return a[0] > b[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>pq(comp);
        int lo = 0, hi = 0, minRange = INT_MAX;
        for(int i = 0; i < nums.size(); i++) hi = max(hi, nums[i][0]), pq.push({nums[i][0], 0, i});
        while(true){
            auto v = pq.top();
            pq.pop();
            lo = v[0];
            if(hi - lo < minRange){
                minRange = min(minRange, hi - lo);
                res[0] = lo;
                res[1] = hi;
            }
            if(++v[1] == nums[v[2]].size()) break;
            v[0] = nums[v[2]][v[1]];
            pq.push(v);
            hi = max(hi, v[0]);
        }
        return res;
    }
};
