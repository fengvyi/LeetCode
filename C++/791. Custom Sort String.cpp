class Solution {
public:
    string customSortString(string S, string T) {
        string res = "";
        vector<int>v(26);
        for(auto c: T) v[c - 'a']++;
        for(auto c: S)
            while(v[c - 'a']--) res.push_back(c);
        for(int i = 0; i < 26; i++)
            while(v[i]-- > 0) res.push_back('a' + i);
        return res;
    }
};
