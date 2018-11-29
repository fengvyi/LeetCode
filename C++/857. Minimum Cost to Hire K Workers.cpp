class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res = INT_MAX;
        int n = quality.size();
        vector<vector<double>>workers;
        for (int i = 0; i < n; ++i) {
            workers.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        int sum = 0;
        priority_queue<int>pq;
        for (auto& x: workers) {
            sum += x[1];
            pq.push(x[1]);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                res = min(res, x[0] * sum);
            }
        }
        return res;
    }
};
