class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        for(int i = 0, j = 0; i < s.size(); j = i){
            int a = 0, b = 0;
            while(j < s.size() && s[j] == s[i]) j++, a++;
            i = j;
            while(j < s.size() && s[j] == s[i]) j++, b++;
            count += min(a, b);
        }
        return count;
    }
};
