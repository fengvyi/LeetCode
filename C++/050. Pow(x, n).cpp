// Iterative.
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return x;
        if(x == -1) return n % 2 ? -1 : 1;
        if(x < 1 && n == INT_MAX || n == INT_MIN) return 0;
        double res=1;
        if(n < 0) x = 1/x, n = -n;
        while(n > 0){
            res = res * x;
            n--;
        }
        return res;
    }
};

// Recursive.
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(x == -1) return n % 2 ? -1 : 1;
        if(n == INT_MIN) return 0;
        if(n == 0) return 1;
        if(n < 0) return 1 / myPow(x, -n);
        if(n % 2) return x * myPow(x, n - 1);
        else{
            double d = myPow(x, n/2);
            return d * d;
        }
    }
};

// A more concise recursive solution from this thread:
// https://discuss.leetcode.com/topic/21837/5-different-choices-when-talk-with-interviewers
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double t = myPow(x,n/2);
        if(n%2) return n<0 ? 1/x*t*t : x*t*t;
        else return t*t;
    }
};
