class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for(int i = 0; i < vec2d.size(); i++) q.push_back(vec2d[i].begin()), end.push_back(vec2d[i].end());
    }

    int next() {
        return *q.front()++;;
    }

    bool hasNext() {
        while(!q.empty() && (q.front() == end.front())) q.pop_front(), end.pop_front();
        return !q.empty();
    }

private:
    deque<vector<int>::iterator>q;
    deque<vector<int>::iterator>end;
};
