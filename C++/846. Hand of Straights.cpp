class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n % W) return false;
        map<int, int>m;
        for(int x: hand) m[x]++;
        auto l = m.begin();
        for(int i = 0; i < n/W; i++){
            auto r = l, t = m.end();
            advance(r, W - 1);
            for(int j = W - 1; j >= 0; j--, r--)
                if((*r).second-- <= 0 || ((*r).first - (*l).first != j)) return false;
                else if((*r).second > 0) t = r;
            if(t != m.end()) l = t;
            else advance(l, W);
        }
        return true;
    }
};
