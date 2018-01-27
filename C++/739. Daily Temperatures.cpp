class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n);
        stack<vector<int>>s;   // stack of <temperature, index>
        for(int i = 0; i < n; i++){
            while(!s.empty() && temperatures[i] > s.top()[0]){
                res[s.top()[1]] = i - s.top()[1];
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};
