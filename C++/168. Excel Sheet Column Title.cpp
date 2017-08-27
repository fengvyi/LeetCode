class Solution {
public:
    string convertToTitle(int n) {
        string res;
        char c;
        while(n){
            c = 'A' + (n - 1) % 26;
            res = c + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};
