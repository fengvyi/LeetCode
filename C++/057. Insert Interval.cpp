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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>res;
        for(auto x: intervals)
            if(x.end >= newInterval.start && x.start <= newInterval.end){
                newInterval.start = min(newInterval.start, x.start);
                newInterval.end = max(newInterval.end, x.end);
            }
        for(auto x: intervals) 
            if(x.end < newInterval.start || x.start > newInterval.end) res.push_back(x);
        for(int i = 0; i < res.size(); i++)
            if(res[i].start > newInterval.start){
                res.insert(res.begin() + i, newInterval);
                break;
            }
        if(res.empty() || res.back().end < newInterval.start) res.push_back(newInterval);
        return res;
    }
};
