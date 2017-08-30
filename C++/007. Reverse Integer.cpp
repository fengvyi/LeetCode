// My Solution
class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int base = 1;
        int i = s[0] == '-' ? 1 : 0;
        int res = 0;
        while(i < s.size()){
            if(base == 1000000000 && (s[i] - '0' > 2 || INT_MAX - (s[i] - '0') * base < res)) return 0;
            res += (s[i] - '0') * base;
            base *= 10;
            i++;
        }
        return s[0] == '-' ? -res : res;
    }
};

// Solution from https://discuss.leetcode.com/topic/6005/shortest-code-possible-in-c
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};
