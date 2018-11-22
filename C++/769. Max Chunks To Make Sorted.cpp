class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0, maxDis = 0;
        for(int i = 0; i < arr.size(); i++){
            maxDis = max(maxDis, arr[i]);
            if(maxDis == i) count++;
        }
        return count;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curMax = 0, n = arr.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            curMax = max(curMax, arr[i]);
            if (curMax == i) {
                ++res;
            }
        }
        return res;
    }
};
