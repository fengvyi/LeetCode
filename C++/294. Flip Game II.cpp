class Solution {
public:
    bool canWin(string s) {
        for(int i = 1; i < s.size(); i++)
            if(s[i - 1] == '+' && s[i] == '+'){
                s[i - 1] = s[i] = '-';
                if(!canWin(s)) return true;
                s[i - 1] = s[i] = '+';
            }
        return false;
    }
};
