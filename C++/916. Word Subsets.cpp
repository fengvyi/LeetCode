class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string>res;
        
        vector<int>maxCount(26);
        
        for (int i = 0; i < B.size(); ++i) {
            vector<int> v = getCount(B[i]);
            
            for (int j = 0; j < 26; ++j) {
                maxCount[j] = max(maxCount[j], v[j]);
            }
        }
        
        for (int i = 0; i < A.size(); ++i) {
            vector<int> v = getCount(A[i]);
            
            bool isValid(true);
            
            for (int j = 0; j < 26; ++j) {
                if (v[j] < maxCount[j]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                res.push_back(A[i]);
            }
        }
        
        return res;
    }
    
    vector<int> getCount(string& s) {
        vector<int>cnt(26);
        
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a']++;
        }
        
        return cnt;
    }
};
