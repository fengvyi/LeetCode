class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>m;
        int maxlen = 0;
        for(int i = 0, j = 0; j < s.size(); j++){
            m[s[j]]++;
            while(m[s[j]] > 1) m[s[i++]]--;
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
