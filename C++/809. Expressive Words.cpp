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

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (auto& x: words) {
            if (isValid(x, S)) {
                ++res;
            }
        }
        return res;
    }
    
    bool isValid(string& x, string& y) {
        if (x.size() > y.size()) {
            return false;
        }
        
        int i = 0, j = 0, m = x.size(), n = y.size();
        while (i < m) {
            if (x[i] != y[j]) {
                return false;
            }
            
            int count1 = 1, count2 = 1;
            while (i + 1 < m && x[i] == x[i + 1]) {
                ++i;
                ++count1;
            }
            
            while(j + 1 < n && y[j] == y[j + 1]) {
                ++j;
                ++count2;
            }
            ++i;
            ++j;
            if (count1 == count2 || (count1 < count2 && count2 >= 3)) {
                continue;
            } else {
                return false;
            }
        }
        return i == m && j == n;
    }
};
