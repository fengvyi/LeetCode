// O(n)
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

// Brute Force, O(n^2), TLE
/*
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int distance = 0;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++)
                distance += helper(nums[i] ^ nums[j]);
        return distance;
    }
    
    int helper(int c){
        int sum = 0;
        while(c){
            sum++;
            c &= c - 1;
        }
        return sum;
    }
};
*/
