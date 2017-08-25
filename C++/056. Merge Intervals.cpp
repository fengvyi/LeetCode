class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){ return a.start < b.start;});
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
            if(intervals[i].start <= res.back().end) res.back().end = max(res.back().end, intervals[i].end);
            else res.push_back(intervals[i]);
        return res;
    }
};
