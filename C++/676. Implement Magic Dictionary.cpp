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

class MagicDictionary {
    struct TrieNode {
        char val;
        vector<TrieNode*> next;
        bool isWord;
        TrieNode(char c): val(c), next(vector<TrieNode*>(26)), isWord(false) {}
    };
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        root = new TrieNode(' ');
        for (auto& s: dict) {
            buildTrie(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(root, word, 0, true);
    }
    
private:
    TrieNode* root;
    
    bool dfs(TrieNode* p, string& word, int pos, bool canModify) {
        if (pos == word.size()) {
            return !canModify && p->isWord;
        }
        bool find = false;
        char c = word[pos];
        if (p->next[c - 'a']) {
            find |= dfs(p->next[c - 'a'], word, pos + 1, canModify);
        } 
        
        if (canModify) {
            for (auto node: p->next) {
                if (node && node->val != c) {
                    find |= dfs(node, word, pos + 1, false);
                }
            }
        }
        return find;
    }
    
    void buildTrie(string& s) {
        TrieNode* p = root;
        for (auto c: s) {
            if (!p->next[c - 'a']) {
                p->next[c - 'a'] = new TrieNode(c);
            }
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
