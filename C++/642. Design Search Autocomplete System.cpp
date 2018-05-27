class AutocompleteSystem {  
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        reset();
        for(int i = 0; i < sentences.size(); i++) buildTrie(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        vector<string>res;
        if(c == '#'){
            buildTrie(sentence, 1);
            reset();
            return res;
        }
        sentence.push_back(c);
        cur = cur->next[c];
        if(!cur) cur = new TrieNode();
        dfs(sentence, cur);
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    struct TrieNode{
        int time;
        unordered_map<char, TrieNode*>next;
        TrieNode():time(0){}
    };
    TrieNode* root;
    TrieNode* cur;
    string sentence;
    
    struct Compare{
        bool operator() (pair<string, int>& p1, pair<string, int>& p2){ 
            return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second; 
        }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare>pq;
    
    void buildTrie(string s, int time){
        auto p = root;
        for(auto c: s){
            if(!p->next[c]) p->next[c] = new TrieNode();
            p = p->next[c];
        }
        p->time += time;
    }
    
    void dfs(string& s, TrieNode* p){
        if(p->time){
            pq.push({s, p->time});
            while(pq.size() > 3) pq.pop();
        }
        for(auto x: p->next){
            s.push_back(x.first);
            dfs(s, x.second);
            s.pop_back();
        }
    }
    
    void reset(){
        cur = root;
        sentence = "";
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
