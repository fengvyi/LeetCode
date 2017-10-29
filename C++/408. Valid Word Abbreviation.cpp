class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while(i < word.size() && j < abbr.size())
            if(isdigit(abbr[j])){ 
                if(abbr[j] == '0') return false;
                int k = j + 1;
                while(k < abbr.size() && isdigit(abbr[k])) k++;
                i += stoi(abbr.substr(j, k - j));
                j = k;
            }
            else if(word[i++] != abbr[j++]) return false;
        return i == word.size() && j == abbr.size();
    }
};
