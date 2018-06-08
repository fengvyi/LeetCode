class LogSystem {
private:
    unordered_map<int, string>log;
    unordered_map<string, int>time{{"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}};

public:
    LogSystem() {}
    
    void put(int id, string timestamp) {
        log[id] = timestamp;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int>res;
        int l = time[gra];
        s = s.substr(0, l);
        e = e.substr(0, l);
        for(auto x: log){
            string t = x.second.substr(0, l);
            if(s.compare(t) <= 0 && e.compare(t) >= 0) res.push_back(x.first);
        }
        return res;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
