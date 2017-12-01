class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        for(auto& x: asteroids)
            if(s.empty() || s.back() < 0 || x > 0) s.push_back(x);
            else{
                while(!s.empty() && s.back() > 0 && abs(x) > s.back()) s.pop_back();
                if(s.empty() || s.back() < 0) s.push_back(x);
                else if(abs(x) == s.back()) s.pop_back();
            }
        return s;
    }
};
