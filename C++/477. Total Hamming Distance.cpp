class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i < 32; i++){
            int one = 0, zero = 0;
            for(auto x: nums) (x & (1 << i)) ? one++ : zero++;
            distance += one * zero;
        }
        return distance;
    }
};
