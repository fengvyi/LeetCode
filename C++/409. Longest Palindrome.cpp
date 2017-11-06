class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        unordered_map<char, int>m;
        for(auto c: s) odd += m[c]++ % 2 ? -1 : 1;
        return min(s.size(), s.size() - odd + 1);
    }
};
