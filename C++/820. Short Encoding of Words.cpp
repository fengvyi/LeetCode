class Solution {
private:
    struct TrieNode{
        int length;
        bool isWord;
        vector<TrieNode*>next;
        TrieNode(int x): length(x), isWord(false), next(vector<TrieNode*>(26)){}
    };
    TrieNode* root;

public:
    int minimumLengthEncoding(vector<string>& words) {
        root = new TrieNode(0);
        int count = 0;
        for(auto& s: words){
            reverse(s.begin(), s.end());
            buildTrie(s, count);
        }
        return count;
    }
    
    void buildTrie(string& s, int& count){
        auto p = root;
        bool newWord = false;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(!p->next[c - 'a']){
                if(!newWord){
                    count++;
                    if(p->isWord){
                        count--;
                        count -= p->length;
                        p->isWord = false;
                    }
                    newWord = true;
                }
                p->next[c - 'a'] = new TrieNode(i + 1);
            }
            p = p->next[c - 'a'];
        }
        if(newWord){
            count += p->length;
            p->isWord = true;
        }
    }
};
