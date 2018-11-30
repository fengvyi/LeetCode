class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        string a, b;
        vector<int>posA, posB;
        for (int i = 0; i < n; ++i) {
            if (start[i] != 'X') {
                a.push_back(start[i]);
                posA.push_back(i);
            }
            if (end[i] != 'X') {
                b.push_back(end[i]);
                posB.push_back(i);
            }
        }
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i] || (a[i] == 'L' && posA[i] < posB[i] || a[i] == 'R' && posA[i] > posB[i])) {
                return false;
            }
        }
        return true;
    }
};
