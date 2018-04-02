class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        vector<char>letter;
        vector<int>count;
        for(int i = 0, index = 0; i < S.size(); index++){
            letter.push_back(S[i]);
            count.push_back(1);
            int j = i + 1;
            while(j < S.size() && S[j] == S[i]) count[index]++, j++;
            i = j;
        }
        
        for(auto s: words){
            vector<char>v;
            vector<int>c;
            bool b = true;
            int index = 0;
            for(int i = 0; i < s.size(); index++){
                v.push_back(s[i]);
                c.push_back(1);
                int j = i + 1;
                while(j < s.size() && s[j] == s[i]) c[index]++, j++;
                if(v[index] != letter[index] || (c[index] != count[index] && count[index] < 3) || c[index] > count[index]){
                    b = false;
                    break;
                }
                i = j;
            }
            if(b && index == count.size()) res++;
        }
        return res;
    }
};
