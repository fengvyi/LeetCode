class Solution {
public:
    int addDigits(int num) {
        return num%9 ? num%9 : num ? 9 : 0; 
    }
};
