class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int>m;
        int odd = 0;
        for(auto c: s) (m[c]++ % 2) ? odd-- : odd++;
        return odd <= 1;
    }
};
