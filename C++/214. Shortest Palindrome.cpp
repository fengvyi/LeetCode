class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int i = 0, j = s.size();
        while(r.substr(i, j) != s.substr(0, j)) i++, j--;
        return r.substr(0, i) + s;
    }
};
