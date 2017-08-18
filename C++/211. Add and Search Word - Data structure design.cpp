class WordDictionary {
private:
    unordered_map<int, vector<string>>words;
    
    bool isEqual(string a, string b){
        for(int i = 0; i < a.size(); i++){
            if(b[i] == '.') continue;
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. 
    A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        for(auto s: words[word.size()])
            if(isEqual(s, word)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
