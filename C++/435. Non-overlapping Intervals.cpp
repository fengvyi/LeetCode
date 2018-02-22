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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){ return a.start < b.start; });
        int count = 0;
        for(int i = 1,  j = 0; i < intervals.size(); i++){
            int pre = i;
            if(intervals[i].start < intervals[j].end){
                count++;
                if(intervals[i].end > intervals[j].end) pre = j;
            }
            j = pre;
        }
        return count;
    }
};
