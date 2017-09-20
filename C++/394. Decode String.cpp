class Solution {
public:
    string decodeString(string s) {
        if(s.empty()) return "";
        string res = "";
        int i = 0, j = 0;
        while(j < s.size()){
            while(j < s.size() && isalpha(s[j])) j++;
            res += s.substr(i, j - i);
            i = j;
            if(j == s.size()) break;
            while(isdigit(s[j])) j++;
            int k = stoi(s.substr(i, j - i));
            int cnt = 1;
            i = j + 1;
            while(cnt != 0)
                if(s[++j] == ']') cnt--;
                else if(s[j] == '[') cnt++;
            while(k--) res += decodeString(s.substr(i, j - i));
            i = ++j;
        }
        return res;
    }
};
