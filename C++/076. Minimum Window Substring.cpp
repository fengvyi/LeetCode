class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>m;
        int i = 0, j = 0, count = 0, minLen = INT_MAX;
        string res = "";
        for(auto x: t) m[x]++, count++;
        while(j < s.size()){
            if(m[s[j++]]-- > 0) count--;
            if(count == 0){
                while(m[s[i]] < 0) m[s[i++]]++;
                int len = j - i;
                if(len < minLen){
                    minLen = len;
                    res = s.substr(i, len);
                }
                m[s[i++]]++;
                count++;
            }
        }
        return res;
    }
};
