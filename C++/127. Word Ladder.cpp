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
