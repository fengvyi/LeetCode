class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = -1, d = 0;
        for(auto x: seats) if(x) res = max(res, res == -1 ? d : d/2), d = 1; else d++;
        return max(res, d - 1);
    }
};
