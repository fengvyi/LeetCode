// Solution 1. Straight forward, 165ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxlen = 0;
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++){
                if(words[i].size() * words[j].size() <= maxlen) continue;
                if(noCommon(words[i], words[j])) maxlen = max(maxlen, (int)(words[i].size() * words[j].size()));
            }
        return maxlen;
    }
    
    bool noCommon(string& a, string& b){
        for(auto x: a) 
            for(auto y: b)
                if(x == y) return false;
        return true;
    }
};

// Solution 2. Bit Manipulation, 43ms
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxlen = 0;
        vector<int>val(words.size());
        for(int i = 0; i < words.size(); i++)
            for(auto c: words[i]) val[i] |= (1 << (c - 'a'));
        
        for(int i = 0; i < words.size(); i++)
            for(int j = i + 1; j < words.size(); j++)
                if((val[i] & val[j]) == 0 && words[i].size() * words[j].size() > maxlen)
                    maxlen = max(maxlen, (int)(words[i].size() * words[j].size()));
        return maxlen;
    }
};
