// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       int lower = 1, upper = n;
       while(lower < upper)
           if(isBadVersion(lower + (upper - lower)/2)) upper = lower + (upper - lower)/2;
           else lower = lower + (upper - lower)/2 + 1;
       return lower;
    }
};
