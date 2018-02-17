class MapSum {
    struct TrieNode{
        int sum;
        TrieNode* next[26];
        TrieNode(): sum(0){
            memset(next, NULL, sizeof(next));
        }
    };
    
    unordered_map<string, int>m;
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        bool replace = false;
        if(m.count(key)) replace = true;
        TrieNode* p = root;
        for(char c: key){
            if(!p->next[c - 'a']) p->next[c - 'a'] = new TrieNode();
            p = p->next[c - 'a'];
            p->sum += replace ? val - m[key] : val;
        }
        m[key] = val;
    }
    
    int sum(string prefix) {
        TrieNode* p = root;
        for(char c: prefix){
            if(!p->next[c - 'a']) return 0;
            p = p->next[c - 'a'];
        }
        return p->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
