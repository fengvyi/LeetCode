class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto c: s){
            if(stk.empty() && c != '(' && c != '[' && c != '{') return false;
            else if((c == ')' && stk.top() != '(') || (c == ']' && stk.top() != '[') || (c == '}' && stk.top() != '{'))
                return false;
            if(c == '(' || c == '[' || c== '{') stk.push(c);
            else stk.pop();
        }
        return stk.empty();
    }
};
