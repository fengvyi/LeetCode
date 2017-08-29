class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = 0, j = citations.size() - 1;
        while(j >= 0 && citations[j] > i) i++, j--;
        return i;
    }
};
