class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int step = 1;
        deque<string>cur;
        deque<string>next;
        cur.push_back(start);
        while(!cur.empty()){
            string node = cur.front();
            cur.pop_front();
            for(auto& s: bank){
                if(s == "" || !isNeighbor(node, s)) continue;
                if(s == end) return step;
                next.push_back(s);
                s = "";
            }
            if(cur.empty()){
                step++;
                swap(cur, next);
            }
        }
        return -1;
    }
    
    bool isNeighbor(const string& a, const string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};
