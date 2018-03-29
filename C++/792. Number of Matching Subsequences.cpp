class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        vector<vector<int>>bucket(26);
        for(int i = 0; i < S.size(); i++) bucket[S[i] - 'a'].push_back(i);
        for(auto s: words){
            int pre = -1, cur = -1, i = 0;
            for(;i < s.size(); i++){
                for(auto x: bucket[s[i] - 'a']){
                    if(x > pre){
                        cur = x;
                        break;
                    }
                }
                if(cur == pre) break;
                pre = cur;
            }
            if(i == s.size()) res++;
        }
        return res;
    }
};
