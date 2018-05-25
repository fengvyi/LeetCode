class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count = s1.size();
        unordered_map<char, int>m;
        for(auto c: s1) m[c]++;
        int l = 0, r = 0;
        while(r < s2.size()){
            if(m[s2[r++]]-- > 0) count--;
            while(count == 0){
                if(r - l == s1.size()) return true;
                if(m[s2[l++]]++ == 0) count++;
            }  
        }
        return false;
    }
};
