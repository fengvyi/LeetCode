class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen = 0, i = 0, j = 0, next = 0;
        unordered_set<char>set;
        while(j < s.size()){
            j = i;
            while(j < s.size()){
                if(set.size() == 1) next = j;
                set.insert(s[j]);
                if(set.size() > 2){
                    maxlen = max(maxlen, j - i);
                    i = next;
                    set.clear();
                    break;
                }
                j++;
            }
        }
        maxlen = max(maxlen, j - i);
        return maxlen;
    }
};
