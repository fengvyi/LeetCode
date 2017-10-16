class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        if(picture.empty()) return 0;
        int m = picture.size(), n = picture[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            bool B = true;
            for(int j = 0; j < n && B; j++){
                if(picture[i][j] == 'B'){
                    B = false;
                    int r = 0, c = j + 1;
                    for(; r < m; r++) if(r != i && picture[r][j] == 'B') break;
                    for(; c < n; c++) if(picture[i][c] == 'B') break;
                    if(r == m && c == n) count++;
                }
            }
        }
        return count;
    }
};
