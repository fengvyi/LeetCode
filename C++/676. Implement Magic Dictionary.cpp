// Solution 1. Hash Table
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto x: dict) m[x.size()].push_back(x);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto x: m[word.size()])
            if(oneEditDistance(x, word)) return true;
        return false;
    }
    
private:
    unordered_map<int, vector<string>>m;
    bool oneEditDistance(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size() && diff <= 1; i++)
            if(a[i] != b[i]) diff++;
        return diff == 1;
    }
};

// Solution 2. Trie
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto x: dict) buildTrie(x);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        TrieNode* p = root;
        int diff = 0;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            for(int j = 0; j < 26; j++){
                if(p->next[j] == p->next[c - 'a']) continue;
                if(p->next[j] && find(p->next[j], word.substr(i + 1))) return true;
            }
            if(p->next[c - 'a']) p = p->next[c - 'a'];
        }
        return false;
    }

private:
    struct TrieNode{
        bool isWord;
        TrieNode* next[26];
        TrieNode():isWord(false){
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode* root;
    
    void buildTrie(string s){
        TrieNode* p = root;
        for(auto c: s){
            if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }
    
    bool find(TrieNode* p, string s){
        for(auto c: s)
            if(p->next[c - 'a']) p = p->next[c - 'a'];
            else return false;
        return p->isWord;
    }
};
