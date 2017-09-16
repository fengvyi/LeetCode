/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->nestedList = &nestedList;
    }

    int next() {
        int n = q.front();
        q.pop_front();
        return n;
    }

    bool hasNext() {
        while(q.empty() && i < nestedList->size()){
            if((*nestedList)[i].isInteger())
                q.push_back((*nestedList)[i].getInteger());
            else{
                NestedIterator* it = new NestedIterator((*nestedList)[i].getList());
                while(it->hasNext()) q.push_back(it->next());
            }
            i++;
        }
        return !q.empty();
    }

private:
    vector<NestedInteger>* nestedList;
    deque<int>q;
    int i = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
