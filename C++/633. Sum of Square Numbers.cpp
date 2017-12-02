class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0, b = sqrt(c); a <= sqrt(c); a++, b = sqrt(c - a * a))
            if(b * b == c - a * a) return true;
        return false;
    }
};
