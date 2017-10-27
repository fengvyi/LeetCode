class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string>res;
        for(int i = 1; i < s.size(); i++)
            if(s[i - 1] == '+' && s[i] == '+'){
                res.push_back(s);
                res.back()[i - 1] = '-';
                res.back()[i] = '-';
            }
        return res;
    }
};
