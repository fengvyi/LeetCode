class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>tower((1 + 100) * 100 / 2);
        tower[0] = poured;
        for(int i = 0; i < 99; i++){
            for(int j = 0; j <= i; j++){
                int idx = index(i, j);
                if(tower[idx] > 1){
                    double remain = tower[idx] - 1;
                    tower[idx] = 1;
                    tower[index(i + 1, j)] += remain / 2;
                    tower[index(i + 1, j + 1)] += remain / 2;
                }
            }
        }
        return tower[index(query_row, query_glass)];
    }
    
    int index(int row, int col){
        return row * (row + 1) / 2 + col;
    }
};
