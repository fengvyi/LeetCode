class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char>m{{'6', '9'}, {'9', '6'}, {'1', '1'}, {'0', '0'}, {'8', '8'}};
        string s = "";
        for(auto x: num)
            if(!m.count(x)) return false;
            else s.push_back(m[x]);
        reverse(s.begin(), s.end());
        return s == num;
    }
};
