class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s.front() == '0') return 0;
        int mod = pow(10, 9) + 7;
        long p1 = (s[0] == '*') ? 9 : 1, p2 = 1, t;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '0') p1 = 0;
            
            if(s[i - 1] != '*' && s[i] != '*'){
                if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7'){
                    p1 = p1 + p2;
                    p2 = p1 - p2;
                }
                else p2 = p1;
            }
            else{
                if(s[i - 1] == '*' && s[i] == '*'){
                    t = p1;
                    p1 = p1 * 9 + p2 * (9 + 6);
                    p2 = t;
                }
                else if(s[i] == '*'){
                    if(s[i - 1] == '1'){
                        t = p1;
                        p1 = p1 * 9 + p2 * 9;
                        p2 = t;
                    }
                    else if(s[i - 1] == '2'){
                        t = p1;
                        p1 = p1 * 9 + p2 * 6;
                        p2 = t;
                    }else{
                        t = p1;
                        p1 = p1 * 9;
                        p2 = t;
                    }
                }
                else{
                    if(s[i] == '0'){
                        t = p1;
                        p1 = p2 * 2;
                        p2 = t;
                    }
                    else if(s[i] < '7'){
                        t = p1;
                        p1 = p1 + p2 * 2;
                        p2 = t;
                    }
                    else{
                        p1 = p1 + p2;
                        p2 = p1 - p2;
                    }
                }
            }
            p1 = p1 % mod;
        }
        return p1;
    }
};
