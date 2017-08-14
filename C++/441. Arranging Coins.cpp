class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n >= i) n -= i, i++;
        return i - 1;
    }
};

// Math solution from this thread https://discuss.leetcode.com/topic/65655/c-1-line-code
class Solution {
public:
    int arrangeCoins(int n) {
        return floor(-0.5+sqrt((double)2*n+0.25));
    }
};
