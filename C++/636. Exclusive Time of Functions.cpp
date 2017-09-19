class Solution {
private:
    struct Log{
        int id;
        int time;
        int append;
        Log(int x, int y, int z): id(x), time(y), append(z){}
    };
    
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>res(n);
        stack<Log*>s;
        int id = 0, time = 0;
        string op = "", str = "";
        for(int i = 0; i < logs.size(); i++){
            stringstream ss(logs[i]);
            getline(ss, str, ':');
            id = stoi(str);
            getline(ss, str, ':');
            op = str;
            getline(ss, str, ':');
            time = stoi(str);
            Log* l = new Log(id, time, 0);
            if(op == "start"){
                if(!s.empty()) s.top()->append += l->time - s.top()->time;
                s.push(l);
            }
            else{
                res[id] += l->time - s.top()->time + 1 + s.top()->append;
                s.pop();
                if(!s.empty()) s.top()->time = l->time + 1;
            }
        }
        return res;
    }
};
