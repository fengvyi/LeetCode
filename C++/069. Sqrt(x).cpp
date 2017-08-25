// Solution 1. Binary Search
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return x;
        int lo = 1, hi = x;
        while (true) {
            int mid = lo + (hi - lo)/2;
            if (mid > x/mid) hi = mid - 1;
            else if (mid + 1 > x/(mid + 1)) return mid;
            else lo = mid + 1;
        }
    }
};

// Solution 2. Newton's Method.
/**
 *  Guess Result        Quotient                             Average Result
 *         1          2 / 1 = 2                            (2 + 1) / 2 = 1.5
 *        1.5      2 / 1.5 = 1.3333                (1.3333 + 1.5) / 2 = 1.4167
 *      1.4167    2 / 1.4167 = 1.4118          (1.4167 + 1.4118) / 2 = 1.4142
 */
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};
