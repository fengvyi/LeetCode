/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int>res;
        map<int, int>m;
        for(int i = 0; i < intervals.size(); i++) m[intervals[i].start] = i;
        for(auto i: intervals){
            auto p = m.lower_bound(i.end);
            res.push_back(p == m.end() ? -1 : (*p).second);
        }
        return res;
    }
};
