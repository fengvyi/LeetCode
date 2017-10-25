class Solution {
public:
    int calculate(string s) {
        stack<int>stk, op;
        int res = 0, sign = 1;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(isdigit(c)){
                int num = c - '0';
                while(i + 1 < s.size() && isdigit(s[i + 1])){
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                res += num * sign;
            }
            else if(c == '+') sign = 1;
            else if(c == '-') sign = -1;
            else if(c == '('){
                stk.push(res);
                op.push(sign);
                res = 0;
                sign = 1;
            }
            else if(c == ')'){
                res = res * op.top();
                op.pop();
                res += stk.top();
                stk.pop();
            }
        }
        return res;
    }
};
