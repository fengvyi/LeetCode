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
        this->nestedList = nestedList;
    }

    int next() {
        int num = current.front();
        current.pop_front();
        return num;
    }

    bool hasNext() {
        while(k != nestedList.size() && current.empty()){
            if(nestedList[k].isInteger()) {
                current.push_back(nestedList[k].getInteger());
                k++;
                break;
            }
            NestedIterator i(nestedList[k].getList());
            while(i.hasNext()) current.push_back(i.next());
            k++;
        }
        return !current.empty();
    }
    
private:
    vector<NestedInteger>nestedList; 
    deque<int>current;
    int k = 0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
