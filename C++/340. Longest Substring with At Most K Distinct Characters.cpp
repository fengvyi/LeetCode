class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int>m;
        int i = 0, j = 0, cnt = 0, maxlen = 0;
        while(j < s.size()){
            if(m[s[j++]]++ == 0) cnt++;
            if(cnt <= k) maxlen = max(maxlen, j - i);
            while(cnt > k) if(--m[s[i++]] == 0) cnt--;
        }
        return maxlen;
    }
};
