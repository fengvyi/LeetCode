class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1(0), candidate2(0), count1(0), count2(0);
        for(auto x: nums){
            if(count1 == 0 && x != candidate2) candidate1 = x;
            if(count2 == 0 && x != candidate1) candidate2 = x;
            if(x == candidate1) count1++;
            if(x == candidate2) count2++;
            if(x != candidate1 && x!= candidate2) count1--, count2--;
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
