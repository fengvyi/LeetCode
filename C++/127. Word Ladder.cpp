class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        deque<string>cur;
        deque<string>next;
        cur.push_back(beginWord);
        int len = 2;
        while(!cur.empty()){
            string node = cur.front();
            cur.pop_front();
            for(auto& x: wordList){
                if(x == "" || !isNeighbor(node, x)) continue;
                if(x == endWord) return len;
                next.push_back(x);
                x = "";
            }
            if(cur.empty()){
                len++;
                swap(cur, next);
            }
        }
        return 0;
    }
    
    bool isNeighbor(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};

// Two-end.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_set<string>visited0, visited1, *v0(&visited0), *v1(&visited1);
        deque<string>cur0, next0, cur1, next1, *cur, *next;
        cur0.push_back(beginWord);
        cur1.push_back(endWord);
        visited0.insert(beginWord);
        visited1.insert(endWord);
        int len = 2;
        bool b = true;
        while(!cur0.empty() && !cur1.empty()){
            cur = b ? &cur0 : &cur1;
            next = b ? &next0 : &next1;
            string node = cur->front();
            cur->pop_front();
            for(auto& x: wordList){
                if(v0->count(x) || !isNeighbor(node, x)) continue;
                if(v1->count(x)) return len;
                v0->insert(x);
                next->push_back(x);
            }
            if(cur->empty()){
                len++;
                swap(*cur, *next);
                swap(v0, v1);
                b = !b;
            }
        }
        return 0;
    }
    
    bool isNeighbor(string& a, string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};
