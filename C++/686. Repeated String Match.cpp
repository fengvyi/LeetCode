class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 0, j = 0, count = 1;
        while(j < B.size()){
            while(i < A.size() && A[i] != B[j]) i++;
            if(i == A.size() || count > 1) return -1;
            while(j < B.size() && A[i++] == B[j++]){
                if(j == B.size()) return count;
                if(i == A.size()) i = 0, count++;
            }
            j = 0;
        }
    }
};
