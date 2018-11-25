class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        stack<char>q;
        stack<int>idx;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (q.empty() || q.top() <= s[i]) {
                q.push(s[i]);
                idx.push(i);
            } else {
                int pos = -1;
                while (!q.empty() && q.top() > s[i]) {
                    pos = idx.top();
                    q.pop();
                    idx.pop();
                }
                swap(s[i], s[pos]);
                sort(s.begin() + i + 1, s.end());
                long l = stol(s);
                if (l > INT_MAX) return -1;
                return l;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        auto res = stol(s);
        return (res > INT_MAX || res <= n) ? -1 : res;
        return -1;
    }
};
