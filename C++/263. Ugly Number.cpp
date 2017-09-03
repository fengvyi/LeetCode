class Solution {
public:
    bool isUgly(int num) {
        return num ? !(num%2) ? isUgly(num/2) : !(num%3) ? isUgly(num/3) : !(num%5) ? isUgly(num/5) : num == 1 : false;
    }
};
