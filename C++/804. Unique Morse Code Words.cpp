class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>s;
        for(string x: words){
            string t = "";
            for(char c: x) t += table[c - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};
