// Two Pointers
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, countA = 0, countB = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0 && (S[i] == '#' || countA > 0)) S[i--] == '#' ? ++countA : --countA;
            while(j >= 0 && (T[j] == '#' || countB > 0)) T[j--] == '#' ? ++countB : --countB;
            if(i < 0 || j < 0) return i == j;
            if(S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};

// Stack
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a = "", b = "";
        for(auto c: S) c == '#' ? a.size() > 0 ? a.pop_back() : void() : a.push_back(c);
        for(auto c: T) c == '#' ? b.size() > 0 ? b.pop_back() : void() : b.push_back(c);
        return a == b;
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size() - 1, j = T.size() - 1, count1 = 0, count2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || count1 > 0)) {
                if (S[i] == '#') {
                    ++count1;
                } else {
                    --count1;
                }
                --i;
            }
            
            while (j >= 0 && (T[j] == '#' || count2 > 0)) {
                if (T[j] == '#') {
                    ++count2;
                } else {
                    --count2;
                }
                --j;
            }
            
            if (i < 0 || j < 0) {
                return i == j;
            }
            
            if (S[i] != T[j]) {
                return false;
            }
            --i;
            --j;
        }
        return true;
    }
};
