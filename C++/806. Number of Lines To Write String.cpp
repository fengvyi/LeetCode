class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 1, sum = 0;
        for(char c: S){
            sum += widths[c - 'a'];
            if(sum > 100) sum = widths[c - 'a'], line++;
        }
        return {line, sum};
    }
};
