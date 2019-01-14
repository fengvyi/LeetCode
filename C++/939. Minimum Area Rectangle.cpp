class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = 0;
        set<pair<int, int>>s;
        for (auto& p: points) {
            s.insert({p[0], p[1]});
        }
        
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                auto a = points[i];
                auto b = points[j];
                
                if (a[0] == b[0] || a[1] == b[1]) {
                    continue;
                }

                pair<int, int> c = {b[0], a[1]};
                pair<int, int> d = {a[0], b[1]};
                
                if (s.count(c) && s.count(d)) {
                    int area = abs(a[1] - b[1]) * abs(b[0] - a[0]);
                    minArea = minArea ? min(minArea, area) : area;
                }
            }
        }
        return minArea;
    }
};
