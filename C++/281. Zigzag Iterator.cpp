class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = v1.begin();
        it2 = v2.begin();
        end1 = v1.end();
        end2 = v2.end();
    }

    int next() {
        if(it1 == end1) return *it2++;
        if(it2 == end2) return *it1++;
        int res = turn ? *it1++ : *it2++;
        turn = !turn;
        return res;
    }

    bool hasNext() {
        return it1 != end1 || it2 != end2;
    }

private:
    vector<int>::iterator it1, it2, end1, end2;
    bool turn = true;
};

// Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
// Solution: For k vectors, use two queues to store iterators and `end` iterators.
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        auto it1 = v1.begin();
        auto it2 = v2.begin();
        auto end1 = v1.end();
        auto end2 = v2.end();
        it.push_back(it1);
        it.push_back(it2);
        end.push_back(end1);
        end.push_back(end2);
        /*  If given k vectors
        (vector<vector<int>>& v){
            for(auto x: v){
                auto i = v.begin(); 
                auto j = v.end();
                it.push_back(i);
                end.push_back(j);
            }
        }
        */
    }

    int next() {
        auto x = it.front();
        it.pop_front();
        int res = *x++;
        it.push_back(x);
        end.push_back(end.front());
        end.pop_front();
        return res;
    }

    bool hasNext() {
        while(!it.empty() && it.front() == end.front()){
            it.pop_front();
            end.pop_front();
        }
        return !it.empty();
    }

private:
    deque<vector<int>::iterator>it;
    deque<vector<int>::iterator>end;
};
