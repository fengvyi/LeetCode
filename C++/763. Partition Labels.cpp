// Straightforward two pointers:
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>res;
        int maxPos = 0, pre = -1;
        for(int i = 0; i < S.size(); i++){
            for(int j = maxPos + 1; j < S.size(); j++) 
                if(S[j] == S[i]) maxPos = max(maxPos, j);
            if(i == maxPos){
                res.push_back(i - pre);
                pre = i;
            }
        }
        return res;
    }
};

// O(N)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int>res;
        vector<int>pos(26);
        for(int i = 0; i < S.size(); i++) pos[S[i] - 'a'] = i;
        int maxPos = 0, pre = -1;
        for(int i = 0; i < S.size(); i++){
            maxPos = max(maxPos, pos[S[i] - 'a']);
            if(i == maxPos){
                res.push_back(i - pre);
                pre = i;
            }
        }
        return res;
    }
};
