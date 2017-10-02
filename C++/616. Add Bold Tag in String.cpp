struct TrieNode{
    bool isWord = false;
    unordered_map<char, TrieNode*>next;
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string t = "";
        buildTrie(dict);
        for(int i = 0; i < s.size(); i++){
            auto p = root;
            int j = i;
            while(j < s.size() && p->next.count(s[j]))
                p = p->next[s[j++]];
            if(p != root && p->isWord){
                int pos = j;
                for(int k = i + 1; k < pos; k++){
                    int l = k;
                    auto v = root;
                    while(l < s.size() && v->next.count(s[l]))
                        v = v->next[s[l++]];
                    pos = max(pos, l);
                }
                t += '(' + s.substr(i, pos - i) + ')';
                i = pos - 1;
            }
            else t.push_back(s[i]);
        }
        string res = "";
        for(int i = 0; i < t.size(); i++){
            if(i + 1 < t.size() && t[i] == ')' && t[i + 1] == '(') i += 2;
            (t[i] == '(') ? res += "<b>" : (t[i] == ')') ? res += "</b>" : res += t[i];
        }
        return res;
    }
    
private:
    TrieNode* root;
    void buildTrie(vector<string>& dict){
        root = new TrieNode();
        for(auto x: dict){
            auto p = root;
            for(auto c: x){
                if(!p->next.count(c))
                    p->next[c] = new TrieNode();
                p = p->next[c];
            }
            p->isWord = true;
        }
    }
};
