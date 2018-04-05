class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<int>v(n + 1);
        vector<int>m(n + 1);
        string res = "";
        for(auto s: words){
            auto pos = S.find(s);
            while(pos != string::npos){
                v[pos]++;
                v[pos + s.size()]--;
                pos = S.find(s, pos + 1);
            }
        }
        int pre = 0, cur = 0;
        for(int i = 0; i < n + 1; i++){
            cur = pre + v[i];
            if(pre == 0 && cur > 0) m[i] = 1;
            else if(pre > 0 && cur == 0) m[i] = -1;
            pre = cur;
        }
        for(int i = 0; i < n + 1; i++){
            if(m[i]) res += m[i] == 1 ? "<b>" : "</b>";
            if(i < n) res.push_back(S[i]);
        }
        return res;
    }
};
