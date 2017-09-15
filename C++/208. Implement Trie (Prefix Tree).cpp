// Solution 1
// My cheat solution, it's not a tree, but maybe the shortest solution of all.
class Trie {
private:
    unordered_set<string>s;
public:
    Trie() {}
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return s.count(word);
    }
    
    bool startsWith(string prefix) {
        for(auto x: s){
            if(x.size() < prefix.size()) continue;
            int i = 0;
            while(i < prefix.size() && x[i] == prefix[i]) i++;
            if(i == prefix.size()) return true; 
        }
        return false;
    }
};

// Solution 2
// Normal solution.
struct TrieNode{
    bool isWord;
    vector<TrieNode*>next;
    TrieNode():isWord(false){
        next = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for(auto c: word){
            if(!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = find(word);
        return node && node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = find(prefix);
        return node;
    }
private:
    TrieNode* root;
    
    TrieNode* find(string s){
        TrieNode* node = root;
        for(auto c: s){
            if(!node->next[c - 'a']) return NULL;
            node = node->next[c - 'a'];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
