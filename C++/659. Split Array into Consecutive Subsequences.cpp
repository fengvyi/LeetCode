class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>m, f;
        for(auto x: nums) m[x]++;
        for(auto x: nums){
            if(!m[x]) continue;
            else if(f[x]){
                f[x]--;
                f[x + 1]++;
            }
            else if(m[x + 1] && m[x + 2]){
                m[x + 1]--;
                m[x + 2]--;
                f[x + 3]++;
            }
            else return false;
            m[x]--;
        }
        return true;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>m, t;
        for (int& x: nums) {
            ++m[x];
        }
        
        for (int& x: nums) {
            if (!m[x]) {
                continue;
            }
            --m[x];
            if (t[x]) {
                --t[x];
                ++t[x + 1];
            } else if (m[x + 1] && m[x + 2]) {
                --m[x + 1];
                --m[x + 2];
                ++t[x + 3];
            } else {
                return false;
            }
        }
        return true;
    }
};
