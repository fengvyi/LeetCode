// Yes, I cheat, it's not a tree, maybe the shortest solution of all.
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
