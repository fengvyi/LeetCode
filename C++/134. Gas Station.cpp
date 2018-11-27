class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n(gas.size()), sum(0), total(0), res(0);
        for (int i = 0; i < n; ++i) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? res : -1;
    }
};
