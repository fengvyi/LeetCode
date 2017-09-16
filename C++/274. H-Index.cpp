// Solution 1.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = 0, j = citations.size() - 1;
        while(j >= 0 && citations[j] > i) i++, j--;
        return i;
    }
};

// Solution 2.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>buckets(n + 1);
        for(auto x: citations) x >= n ? buckets[n]++ : buckets[x]++;
        int count = 0;
        for(int i = n; i >= 0; i--){
            count += buckets[i];
            if(count >= i) return i;
        }
        return 0;
    }
};
