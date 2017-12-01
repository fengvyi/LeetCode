class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>res;
        for(int i = left; i <= right; i++)
            if(isValid(i)) res.push_back(i);
        return res;
    }
    
    bool isValid(int num){
        int n = num;
        while(n){
            if(!(n % 10) || num % (n % 10)) return false;
            n /= 10;
        }
        return true;
    }
};
