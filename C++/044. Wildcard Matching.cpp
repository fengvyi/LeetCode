// My TLE recursion (1611/1805).
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(s.empty()) return p.empty() || p[0] == '*' ? isMatch(s, p.substr(1)) : false;
        if(p[0] != '?' && p[0] != '*' && p[0] != s[0]) return false; 
        if(p[0] == '*'){
            for(int i = 0; i <= s.size(); i++)
                if(isMatch(s.substr(i), p.substr(1))) return true;
            return false;
        }
        return isMatch(s.substr(1), p.substr(1));
    }
};

// An O(n) C++ based on this [post](https://discuss.leetcode.com/topic/3040/linear-runtime-and-constant-space-solution).
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, ss = 0, star = -1;
        while(i < s.size()){
            if(j < p.size() && (p[j] == '?' || s[i] == p[j])){
                i++;
                j++;
            }
            else if(j < p.size() && p[j] == '*'){
                star = j;
                ss = i;
                j++;
            }
            else if(star != -1){
                j = star + 1;
                i = ++ss;
            }
            else return false;
        }
        while(j < p.size() && p[j] == '*') j++;
        return j == p.size();
    }
};
