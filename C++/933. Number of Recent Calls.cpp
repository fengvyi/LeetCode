class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while (!q.empty() && t - q.front() > 3000) {
            q.pop_front();
        }
        q.push_back(t);
        return q.size();
    }

private:
    deque<int>q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
