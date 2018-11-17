class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int a = 0, b = 0, n = name.size(), m = typed.size();
        while (a < n && b < m) {
            if (name[a++] != typed[b++]) return false;
            while (b > 0 && name[a] != typed[b] && typed[b] == typed[b - 1]) ++b;
        }
        return a == n && b == m;
    }
};
