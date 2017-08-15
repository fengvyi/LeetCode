class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int d = 0;
        while(n) n &= n-1, d++;
        return d;
    }
};
