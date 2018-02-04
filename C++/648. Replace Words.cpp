class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_map<int, unordered_set<string>>m;
        for(string& s: dict) m[s.size()].insert(s);
        string res = "";
        for(int i = 0, j = 0; i < sentence.size(); i = j + 1, j = i){
            string word = "";
            for(; j < sentence.size() && sentence[j] != ' '; j++){
                string prefix = sentence.substr(i, j - i + 1);
                if(m[prefix.size()].count(prefix) && word.empty()) word = prefix;
            }
            if(word.empty() && j != i) word = sentence.substr(i, j - i);
            res += word + " ";
        }
        res.pop_back();
        return res;
    }
};
