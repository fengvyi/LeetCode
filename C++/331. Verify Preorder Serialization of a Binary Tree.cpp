class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#") return true;
        stringstream ss(preorder);
        stack<int>stk;
        string s = "";
        while(getline(ss, s, ',')){
            if(s == "#" && stk.empty()) return false;
            if(!stk.empty()) stk.top()++;
            if(!stk.empty() && stk.top() == 2) stk.pop();
            if(s != "#") stk.push(0);
            if(stk.empty() && !ss.eof()) return false;
        }
        return stk.empty();
    }
};
