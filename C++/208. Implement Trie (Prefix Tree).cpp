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
            int pos = 0;
            int maxlen = max(x.size(), prefix.size());
            while(pos < maxlen && x[pos] == prefix[pos]) pos++;
            if(pos == prefix.size()) return true; 
        }
        return false;
    }
};

// Solution 2
// Normal solution from this top-voted thread:
// https://discuss.leetcode.com/topic/13463/maybe-the-code-is-not-too-much-by-using-next-26-c
class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};
