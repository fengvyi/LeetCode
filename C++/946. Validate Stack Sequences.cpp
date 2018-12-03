class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s1, s2;
        int m = pushed.size(), n = popped.size();
        for (int i = n - 1; i >= 0; --i) {
            s2.push(popped[i]);
        }
        
        for (int i = 0; i < m; ++i) {
            s1.push(pushed[i]);
            while (!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
                s1.pop();
                s2.pop();
            }
        }
        return s2.empty();
    }
};
