// Solution 1
// Space: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>m;
        for(auto x: nums) if(++m[x] > nums.size()/2) return x;
    }
};

// Solution 2
// [Boyer-Moore Majority Vote algorithm](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html). 
// Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(auto x: nums){
            if(count == 0) candidate = x;
            if(candidate == x) count++;
            else count--;
        }
        return candidate;
    }
};
