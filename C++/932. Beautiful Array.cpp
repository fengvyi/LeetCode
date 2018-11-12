class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res;
        for (int i = 1; i <= N; ++i) {
            res.push_back(i);
        }
        return beautify(res);
    }
    
    vector<int> beautify(vector<int>& v) {
        if (v.size() == 1) {
            return v;
        }
        vector<int> odd, even;
        for (int i = 0; i < v.size(); ++i) {
            if (i % 2) {
                odd.push_back(v[i]);
            } else {
                even.push_back(v[i]);
            }
        }
        auto L = beautify(odd);
        auto R = beautify(even);
        for (const auto& x: R) {
            L.push_back(x);
        }
        return L;
    }
};
