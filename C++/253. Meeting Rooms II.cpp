/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
// Solution 1.
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){ return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(intervals[0].end);
        int room = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < pq.top()) room++;
            else pq.pop();
            pq.push(intervals[i].end);
        }
        return room;
    }
};

// Solution 2.
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int>m;
        int room = 0, maxRoom = 0;
        for(auto x: intervals) m[x.start]++, m[x.end]--;
        for(auto x: m) room += x.second, maxRoom = max(maxRoom, room);
        return maxRoom;
    }
};
