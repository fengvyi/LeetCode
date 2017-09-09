class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto c: s){
            if(stk.empty() && (c == ')' || c == ']' || c == '}')) return false;
            if(c == '(' || c == '[' || c == '{') stk.push(c);
            else{
                char left = stk.top();
                if((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{')) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
