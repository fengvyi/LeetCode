class Solution {
public:
    string nextClosestTime(string time) {
        string cur = time.substr(0, 2) + time.substr(3);
        unordered_set<char>nums;
        for(auto c: cur) nums.insert(c);
        if(nums.size() == 1) return time;
        int minDis = 24 * 60;
        string next = "";
        string res = "";
        DFS(nums, cur, 0, minDis, next, res);
        res.insert(res.begin() + 2, ':');
        return res;
    }

    void DFS(unordered_set<char>& nums, string& cur, int pos, int& minDis, string& next, string& res){
        if(pos == 2 && stoi(next.substr(0, 2)) >= 24) return;
        if(pos == 4){
            if(stoi(next.substr(2)) > 59) return;
            int dis = distance(cur, next);
            if(dis < minDis){
                minDis = dis;
                res = next;
            }
            return;
        }
        
        for(auto c: nums){
            next.push_back(c);
            DFS(nums, cur, pos + 1, minDis, next, res);
            next.pop_back();
        }
    }
    
    int distance(string& cur, string& next){
        int a = stoi(cur.substr(0, 2)) * 60 + stoi(cur.substr(2));
        int b = stoi(next.substr(0, 2)) * 60 + stoi(next.substr(2));
        return a < b ? b - a : b - a + 24 * 60;
    }
};
