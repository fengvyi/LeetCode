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

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int count = 0, j = 0, res = 0;
        unordered_map<char, int>m;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]]++ == 0) {
                ++count;
            }
            
            while (count > k) {
                if (--m[s[j++]] == 0) {
                    --count;
                }
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
