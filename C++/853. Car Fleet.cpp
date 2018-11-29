class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        int res = n;
        vector<vector<int>>cars;
        for (int i = 0; i < n; ++i) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        
        vector<double>time;
        for (int i = 0; i < n; ++i) {
            time.push_back(((double)target - cars[i][0]) / cars[i][1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            if (time[i] <= time[i + 1]) {
                --res;
                time[i] = time[i + 1];
            }
        }
        return res;
    }
};
