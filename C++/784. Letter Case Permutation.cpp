class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string>res;
        DFS(S, 0, res);
        return res;
    }
    
    void DFS(string S, int pos, vector<string>& res){
        if(pos == S.size()){
            res.push_back(S);
            return;
        }
        DFS(S, pos + 1, res);
        char c = S[pos];
        if(isalpha(c)){
            S[pos] = islower(c) ? toupper(c) : tolower(c);
            DFS(S, pos + 1, res);
        }
    }
};
