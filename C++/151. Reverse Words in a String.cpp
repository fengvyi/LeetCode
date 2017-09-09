// O(1) space.
class Solution {
public:
    void reverseWords(string &s) {
        // Reverse string
        reverse(s.begin(), s.end());
        // Reverse every word
        int i = 0, j = 0;
        while(i != s.size()){
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
            while(i < s.size() && s[i] == ' ') i++, j++;
        }
        // Remove extra ' '
        i = 0, j = 0;
        while(j < s.size()){
            bool new_word = false;
            while(j < s.size() && s[j] == ' '){
                new_word = true;
                j++;
            }
            if(j == s.size()) break;
            if(new_word && i > 0) s[i++] = ' ';
            s[i++] = s[j++];
        }
        s = s.substr(0, i);
    }
};

// O(n) space.
class Solution {
public:
    void reverseWords(string &s) {
        string res = "";
        string word = "";
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            while(s[i] == ' ') i++;
            j = i;
            while(s[j] != ' ') j++;
            word = s.substr(i, j - i);
            if(res != "" && word != "") word += " ";
            res = word + res;
            i = j;
        }
        s = res;
    }
};
