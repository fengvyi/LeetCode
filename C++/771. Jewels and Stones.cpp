class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<char>s;
        for(char c: J) s.insert(c);
        for(char c: S) if(s.count(c)) count++;
        return count;
    }
};
