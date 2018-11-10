class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int curLead = -1;
        unordered_map<int, int>count;
        for (int i = 0; i < times.size(); ++i) {
            count[persons[i]]++;
            if(count[persons[i]] >= count[curLead]) {
                curLead = persons[i];
            }
            m[times[i]] = curLead;
        }
    }
    
    int q(int t) {
        return (--m.upper_bound(t))->second;
    }

private:
    
    map<int, int>m;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
