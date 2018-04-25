class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>pos, res;
        for(int i = 0; i < S.size(); i++) if(S[i] == C) pos.push_back(i);
        for(int i = 0, p = 0; i < S.size(); i++){
            if(p < pos.size() && i == pos[p]) p++;
            res.push_back(p == 0 ? pos[0] - i : p == pos.size() ? i - pos[p - 1] : min(i - pos[p - 1], pos[p] - i));
        }
        return res;
    }
};
