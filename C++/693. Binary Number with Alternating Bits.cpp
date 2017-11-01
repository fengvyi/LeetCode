class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n)
            if(!((n & 1) ^ ((n >> 1) & 1))) return false;
            else n >>= 1;
        return true;
    }
};
