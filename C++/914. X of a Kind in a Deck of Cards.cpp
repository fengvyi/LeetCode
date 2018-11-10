class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int>m;
        int n = deck.size();
        for (int i = 0; i < n; ++i) {
            m[deck[i]]++;
        }
        int base = 0;
        for (auto& p: m) {
            base = gcd(p.second, base);
        }
        return base > 1;
    }
    
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
