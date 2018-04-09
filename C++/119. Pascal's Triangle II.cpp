class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        auto v = getRow(rowIndex - 1);
        int n = v.size();
        for(int i = 1; i < n; i++)
            v[i] = (i <= n/2) ? v[i] + v[n - i] : v[n - i];
        v.push_back(1);
        return v;
    }
};
