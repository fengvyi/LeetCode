// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    deque<int>q;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(q.empty()) q.push_front(Iterator::next());
        return q.front();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(!q.empty()){
            int t = q.front();
            q.pop_front();
            return t;
        }
        return Iterator::next();;
	}

	bool hasNext() const {
	    return Iterator::hasNext() || !q.empty();
	}
};
