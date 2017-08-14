// Solution 1
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int>res;
       int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
       for(auto n: nums){
           if(candidate1 == n) 
               count1++;
           else if(candidate2 == n)
               count2++;
           else if(count1 == 0){
               candidate1 = n;
               count1 = 1;
           }
           else if(count2 == 0){
               candidate2 = n;
               count2 = 1;
           }
           else{
               count1--;
               count2--;
           }
       }
       count1 = 0;
       count2 = 0;
       for(auto n: nums)
           if(candidate1 == n)
               count1++;
           else if(candidate2 == n)
               count2++;
       if(count1 > nums.size()/3)
           res.push_back(candidate1);
       if(count2 > nums.size()/3)
           res.push_back(candidate2);
       return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1(0), candidate2(0), count1(0), count2(0);
        for(auto x: nums){
            if(count1 == 0 && x != candidate2) candidate1 = x;
            if(count2 == 0 && x != candidate1) candidate2 = x;
            if(x == candidate1) count1++;
            if(x == candidate2) count2++;
            if(x != candidate1 && x != candidate2) count1--, count2--;
        }
        int check1(0), check2(0);
        for(auto x: nums){
            if(x == candidate1) check1++;
            else if(x == candidate2) check2++;
        }
        if(check1 > nums.size()/3 && check2 > nums.size()/3) return {candidate1, candidate2};
        if(check1 > nums.size()/3) return {candidate1};
        if(check2 > nums.size()/3) return {candidate2};
        return vector<int>();
    }
};
