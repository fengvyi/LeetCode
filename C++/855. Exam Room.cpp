class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        if (s.size() == 0) {
            s.insert(0);
            return 0;
        } else if (s.size() == 1) {
            int pos = *s.begin() < N/2 ? N - 1 : 0;
            s.insert(pos);
            return pos;
        } else {
            int maxDis = -1;
            int res = -1;
            if (!s.count(0)) {
                maxDis = *s.begin() - 1;
                res = 0;
            }
            auto p1 = s.begin();
            auto p2 = p1;
            ++p2;
            while (p2 != s.end()) {
                int pos = (*p2 + *p1)/2;
                int d = min(pos - *p1, *p2 - pos) - 1;
                if (d > maxDis) {
                    maxDis = d;
                    res = (*p1 + *p2)/2;
                }
                ++p1;
                ++p2;
            }
            if (!s.count(N - 1)) {
                auto e = s.end();
                --e;
                int d = N - 1 - *e - 1;
                if (d > maxDis) {
                    res = N - 1;
                }
            }
            s.insert(res);
            return res;
        }
    }
    
    void leave(int p) {
        s.erase(p);
    }
    
private:
    set<int>s;
    int N;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
