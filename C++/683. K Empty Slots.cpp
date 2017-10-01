class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int>s;
        for(int i = 0; i < flowers.size(); i++){
            int l = -1, r = -1;
            if(s.empty()){
                s.insert(flowers[i]);
                continue;
            }
            auto up = s.upper_bound(flowers[i]);
            auto low = up;
            low--;
            if(up == s.end())
                l = flowers[i] - *low - 1;
            else if(up == s.begin())
                r = *up - flowers[i] - 1;
            else{
                l = flowers[i] - *low - 1;
                r = *up - flowers[i] - 1;
            }
            if(l == k || r == k) return i + 1;
            s.insert(flowers[i]);
        }
        return -1;  
    }
};
