// Solution 1. Hash Table, 163 ms.
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

// Solution 2. Trie, 58 ms.
struct TrieNode{
    bool isKey;
    TrieNode* next[26];
    TrieNode(): isKey(false){
        memset(next, NULL, sizeof(next));
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        for(string& s: dict) buildTrie(s);
        string res = "";
        for(int i = 0; i < sentence.size();){
            pair<string, int> nextWord = match(sentence, i);
            res += nextWord.first + " ";
            i = nextWord.second + 1;
        }
        res.pop_back();
        return res;
    }

private:    
    TrieNode* root;
    
    void buildTrie(string& s){
        auto p = root;
        for(char c: s){
            if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->isKey = true;
    }
    
    pair<string, int> match(string& sentence, int pos){
        auto p = root;
        int i = pos;
        while(i < sentence.size() && sentence[i] != ' ' && !p->isKey && p->next[sentence[i] - 'a']){
            p = p->next[sentence[i] - 'a'];
            i++;
        }
        int j = i;
        while(i < sentence.size() && sentence[i] != ' ') i++;
        if(p->isKey) return {sentence.substr(pos, j - pos), i};
        return {sentence.substr(pos, i - pos), i};
    }
};
