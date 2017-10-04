class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(), remain = n - k;
        if(remain == 0) return "0";
        string s = "";
        for(auto x: num){
            while(n > remain && !s.empty() && s.back() - '0' > x - '0'){
                s.pop_back();
                n--;
            }
            s.push_back(x);
        }
        int i = 0;
        while(i < s.size() && s[i] == '0') i++;
        return s.substr(i, remain) == "" ? "0" : s.substr(i, remain);
    }
};
