class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        long sum = 0;
        for(int i = S.size() - 1; i >= 0; sum += shifts[i--]) S[i] = 'a' + (S[i] - 'a' + sum + shifts[i]) % 26;
        return S;
    }
};
